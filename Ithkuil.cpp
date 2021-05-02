//

#define _SILENCE_ALL_CXX17_DEPRECATION_WARNINGS 1
#pragma warning(push, 3)
#pragma warning(disable: 4828)
#include <iostream>
#include <span>
#include <fstream>
#include <string>
#include <optional>
#include <variant>
#include <vector>
#include <array>
#include <string_view>
#include <iomanip>
#include <unordered_map>
#include <algorithm>
#include <stdexcept>
#include <tao/pegtl.hpp>
#include <tao/pegtl/contrib/uint8.hpp>
#include <utf8cpp/utf8.h>
#include <boost/archive/binary_iarchive.hpp>
#include <boost/serialization/serialization.hpp>
#include <fmt/format.h>
#pragma warning(pop)
#pragma warning(default: 4828)
#include "include/ithlib/ir.h"
#include "utf16_console.h"
#include "include/ithlib/morphology.h"
#include "include/ithlib/serialize.h"
#include "include/ithlib/notation.h"
#include "include/ithlib/slot_tables.h"
#include <utf8cpp/utf8.h>
#include <utf8cpp/utf8/cpp11.h>
#include <boost/archive/binary_iarchive.hpp>
#include <boost/serialization/serialization.hpp>
#include <boost/algorithm/string/classification.hpp>
#include <boost/algorithm/string/split.hpp>
#include <tao/pegtl/contrib/trace.hpp>

namespace pegtl = ::tao::pegtl;
namespace v3 = ::ithkuil::v3;

namespace aux
{
	template<typename T>
	constexpr inline auto underlying_cast(T val) -> std::underlying_type_t<T>
	{
		return static_cast<std::underlying_type_t<T>>(val);
	}
}

namespace ithkuil
{
	namespace v3
	{
		namespace pegtl_grammar
		{
			using namespace pegtl;
			namespace b = uint8;

			struct formative_tables
			{
				ithkuil::v3::slot::cv_map_t& cv_map;
				ithkuil::v3::slot::vl_map_t& vl_map;
				ithkuil::v3::slot::cg_map_t& cg_map;
				ithkuil::v3::slot::cs_map_t& cs_map;
				ithkuil::v3::slot::vr_map_t& vr_map;
				ithkuil::v3::slot::vp_map_t& vp_map;
				ithkuil::v3::slot::ca_map_t& ca_map;
				ithkuil::v3::slot::vf_map_t& vf_map;
				ithkuil::v3::slot::cb_map_t& cb_map;
				ithkuil::v3::slot::su_map_t& su_map;
				ithkuil::v3::slot::vx_map_t& vx_map;
				ithkuil::v3::slot::vc_map_t& vc1_map;
				ithkuil::v3::slot::vc_map_t& vc2_map;
				ithkuil::v3::slot::civi_map_t& civi_map;
			};

			struct formative_state
			{
				case_ _case;
				root_t root_;
				std::optional<root_t> inc_root;
				std::optional<std::tuple<perspective, configuration>> inc_pc;
				std::optional<phase> phase_;
				std::optional<sanction> sanction_;
				std::optional<illocution> illocution_;
				std::optional<valence> valence_;
				std::optional<validation> validation_;
				std::optional<aspect> aspect_;
				std::optional<mood> mood_;
				std::optional<v3::newslot::ca::packed_t> ca_;
				std::optional<v3::newslot::vr::packed_t> vr_;
				std::optional<v3::newslot::vp::packed_t> vp_;
				std::optional<v3::newslot::civi::packed_t> civi_;
				std::optional<std::tuple<context, format>> vf_;
				std::optional<bias> bias_;
				std::vector<vxc> vxc_;
				std::vector<ithkuil::v3::case_> inc_cases;

				std::optional<std::tuple<type_t, degree_t>> vx_;
				std::optional<case_> cm;
				vc_mutation m = vc_mutation::none;
				bool fe_errors = false;
			};

			struct consonant : b::range<irs::b, irs::z_caron>
			{};
			struct vowel : b::range<irs::a, irs::u_diaeresis>
			{};
			struct cn_cluster : plus<consonant>
			{};
			struct vw_cluster : plus<vowel>
			{};
			struct gs : b::one<irs::glottal_stop>
			{};
			struct cv : cn_cluster
			{};
			struct vl : vw_cluster
			{};
			struct cg : cn_cluster
			{};
			struct cs : plus<sor<consonant, b::one<irs::syllable_boundary>>>
			{};
			struct vr : seq<vowel, opt<opt<b::one<irs::syllable_boundary>>, vowel>>
			{};
			struct vp : seq<vowel, opt<vowel>>
			{};
			struct ca : cn_cluster
			{};
			struct vf : seq<vowel, opt<opt<b::one<irs::syllable_boundary>>, vowel>>
			{};
			struct vf0 : vf
			{};
			struct vff : vf
			{};
			struct cb : cn_cluster
			{};
			struct su : cn_cluster
			{};
			struct vx : seq<vowel, opt<opt<b::one<irs::syllable_boundary>>, vowel>>
			{};
			struct root_cluster : cn_cluster
			{};
			struct cr : root_cluster
			{};
			struct cx : root_cluster
			{};
			struct vc : plus<sor<vowel, b::one<irs::syllable_boundary, irs::syllable_boundary_vc, irs::glottal_stop>>>
			{};
			struct ci : b::one<irs::h, irs::w, irs::y>
			{};
			struct cim : b::string<irs::h, irs::w>
			{};
			struct vi : vw_cluster
			{};
			struct civi : seq<sor<cim, ci>, vi>
			{};

			struct vf_req
			{};
			struct vf_opt
			{};

			template<typename F, typename... R>
			struct f_tailed
			{};

			struct format_required : success
			{};
			struct format_mustnone : success
			{};

			template<typename... R>
			struct f_tailed<vf_req, R...> : seq<R..., cr, vc, opt<civi>, ca, star<vx, su>, opt<vf, opt<gs, cb>>, format_required, pegtl::eof>
			{};
			template<typename... R>
			struct f_tailed<vf_opt, R...> : seq<R..., cr, vc, opt<civi>, ca, star<vx, su>, opt<vf, opt<gs, cb>>, format_mustnone, pegtl::eof>
			{};

			struct f_pr : f_tailed<vf_req, cv, vl, cs, vr, cx, vp>
			{};
			struct f_r : f_tailed<vf_req, opt<opt<opt<vl>, sor<cs, cg>>, vr>, cx, vp>
			{};
			struct f_p1 : f_tailed<vf_opt, cv, vl, cs, vr>
			{};
			struct f_0 : f_tailed<vf_opt, opt<opt<sor<cs, cg>>, vr, opt<gs, cv, vl>>>
			{};
			struct f_1 : f_tailed<vf_opt, opt<opt<opt<vl>, sor<cs, cg>>, vr>>
			{};

			struct f_rule : sor<f_0, f_1, f_p1, f_r, f_pr>
			{};

			template<typename R>
			struct formative_action : nothing<R>
			{};

			struct avoid_implicit_instantiation
			{
				template<typename ActionInput, typename... States>
				static bool apply(const ActionInput& in, formative_state& state, formative_tables& tables, States&&...)
				{
					constexpr std::array<std::tuple<v3::perspective, v3::configuration>, 36> fexmap { {
							/*{ { 1, v3::suffix::fe01 },*/ { v3::perspective::monadic, v3::configuration::uniplex },
							/*{ { 2, v3::suffix::fe01 },*/ { v3::perspective::monadic, v3::configuration::duplex },
							/*{ { 3, v3::suffix::fe01 },*/ { v3::perspective::monadic, v3::configuration::discrete },
							/*{ { 1, v3::suffix::fe02 },*/ { v3::perspective::monadic, v3::configuration::aggregative },
							/*{ { 2, v3::suffix::fe02 },*/ { v3::perspective::monadic, v3::configuration::segmentative },
							/*{ { 3, v3::suffix::fe02 },*/ { v3::perspective::monadic, v3::configuration::componential },
							/*{ { 1, v3::suffix::fe03 },*/ { v3::perspective::monadic, v3::configuration::coherent},
							/*{ { 2, v3::suffix::fe03 },*/ { v3::perspective::monadic, v3::configuration::composite },
							/*{ { 3, v3::suffix::fe03 },*/ { v3::perspective::monadic, v3::configuration::multiform },
							/*{ { 1, v3::suffix::fe04 },*/ { v3::perspective::unbounded, v3::configuration::uniplex },
							/*{ { 2, v3::suffix::fe04 },*/ { v3::perspective::unbounded, v3::configuration::duplex },
							/*{ { 3, v3::suffix::fe04 },*/ { v3::perspective::unbounded, v3::configuration::discrete },
							/*{ { 1, v3::suffix::fe05 },*/ { v3::perspective::unbounded, v3::configuration::aggregative },
							/*{ { 2, v3::suffix::fe05 },*/ { v3::perspective::unbounded, v3::configuration::segmentative },
							/*{ { 3, v3::suffix::fe05 },*/ { v3::perspective::unbounded, v3::configuration::componential },
							/*{ { 1, v3::suffix::fe06 },*/ { v3::perspective::unbounded, v3::configuration::coherent},
							/*{ { 2, v3::suffix::fe06 },*/ { v3::perspective::unbounded, v3::configuration::composite },
							/*{ { 3, v3::suffix::fe06 },*/ { v3::perspective::unbounded, v3::configuration::multiform },
							/*{ { 1, v3::suffix::fe07 },*/ { v3::perspective::nomic, v3::configuration::uniplex },
							/*{ { 2, v3::suffix::fe07 },*/ { v3::perspective::nomic, v3::configuration::duplex },
							/*{ { 3, v3::suffix::fe07 },*/ { v3::perspective::nomic, v3::configuration::discrete },
							/*{ { 1, v3::suffix::fe08 },*/ { v3::perspective::nomic, v3::configuration::aggregative },
							/*{ { 2, v3::suffix::fe08 },*/ { v3::perspective::nomic, v3::configuration::segmentative },
							/*{ { 3, v3::suffix::fe08 },*/ { v3::perspective::nomic, v3::configuration::componential },
							/*{ { 1, v3::suffix::fe09 },*/ { v3::perspective::nomic, v3::configuration::coherent},
							/*{ { 2, v3::suffix::fe09 },*/ { v3::perspective::nomic, v3::configuration::composite },
							/*{ { 3, v3::suffix::fe09 },*/ { v3::perspective::nomic, v3::configuration::multiform },
							/*{ { 1, v3::suffix::fe10 },*/ { v3::perspective::abstract, v3::configuration::uniplex },
							/*{ { 2, v3::suffix::fe10 },*/ { v3::perspective::abstract, v3::configuration::duplex },
							/*{ { 3, v3::suffix::fe10 },*/ { v3::perspective::abstract, v3::configuration::discrete },
							/*{ { 1, v3::suffix::fe11 },*/ { v3::perspective::abstract, v3::configuration::aggregative },
							/*{ { 2, v3::suffix::fe11 },*/ { v3::perspective::abstract, v3::configuration::segmentative },
							/*{ { 3, v3::suffix::fe11 },*/ { v3::perspective::abstract, v3::configuration::componential },
							/*{ { 1, v3::suffix::fe12 },*/ { v3::perspective::abstract, v3::configuration::coherent},
							/*{ { 2, v3::suffix::fe12 },*/ { v3::perspective::abstract, v3::configuration::composite },
							/*{ { 3, v3::suffix::fe12 },*/ { v3::perspective::abstract, v3::configuration::multiform },
					} };

					const v3::format f { state.vf_ ? std::get<1>(*state.vf_) : v3::format::none };
					// TODO reorder format enum (will require table regeneration)
					const auto fval = [f]
					{
						const auto fval = aux::underlying_cast(f);
						constexpr std::array<decltype(fval), 10> fmap { {
							0, // none
							1, // schemantic
							2, // instrumentative
							7, // objective
							3, // authoritive
							9, // precurrent
							4, // resultative
							5, // subsequent
							6, // concommitant
							9  // affinitive
						} };
						return fmap[fval];
					}();

					bool fe = (fval != 9);
					bool errors_encountered = false;
					state.vxc_.erase(std::remove_if(state.vxc_.begin(),
						state.vxc_.end(),
						[&fexmap, f, fe, &errors_encountered, fval, &inpc = state.inc_pc, &extcases = state.inc_cases](const v3::vxc& vxc_) {
						constexpr int fe01 = aux::underlying_cast(v3::suffix::fe01);
						constexpr int fe12 = aux::underlying_cast(v3::suffix::fe12);
						int suffix = aux::underlying_cast(vxc_._suffix);
						if (suffix >= fe01 && suffix <= fe12)
						{
							if (!fe)
							{
								errors_encountered = true;
								return false;
							}
							const auto [p, c] = fexmap[(suffix - fe01) * 3 + vxc_._type - 1];
							if (inpc)
							{
								const auto [ep, ec] = *inpc;
								if (p == ep && c == ec)
								{
									extcases.push_back(static_cast<v3::case_>(fval * 9 + vxc_._degree - 1));
									return true;
								}
								else
								{
									errors_encountered = true;
								}
							}
							else
							{
								inpc = { p, c };
								extcases.push_back(static_cast<v3::case_>(fval * 9 + vxc_._degree - 1));
								return true;
							}
						}
						return false;
					}),
						state.vxc_.end());
					state.fe_errors = errors_encountered;
					if (!state.inc_cases.empty() || f != v3::format::none)
					{
						return true;
					}
					return false;
				}
			};

			template<>
			struct formative_action<format_required>
			{
				template<typename ActionInput, typename... States>
				static bool apply(const ActionInput& in, formative_state& state, formative_tables& tables, States&&... other)
				{
					return avoid_implicit_instantiation::apply(in, state, tables, other...);
				}
			};

			template<>
			struct formative_action<format_mustnone>
			{
				template<typename ActionInput, typename... States>
				static bool apply(const ActionInput& in, formative_state& state, formative_tables& tables, States&&... other)
				{
					return !avoid_implicit_instantiation::apply(in, state, tables, other...);
				}
			};

			template<>
			struct formative_action<cv>
			{
				template<typename ActionInput, typename... States>
				static bool apply(const ActionInput& in, formative_state& state, formative_tables& tables, States&&...)
				{
					const auto& table = tables.cv_map.left;
					if (auto it = table.find(ithkuil::v3::serialize5(in.begin(), in.end())); it != table.end())
					{
						std::tie(state.phase_, state.sanction_, state.illocution_) = static_cast<v3::newslot::cv::value_t>(v3::newslot::cv(it->second));
						return true;
					}
					return false;
				}
			};

			template<>
			struct formative_action<vl>
			{
				template<typename ActionInput, typename... States>
				static bool apply(const ActionInput& in, formative_state& state, formative_tables& tables, States&&...)
				{
					const auto& table = tables.vl_map.left;
					if (auto it = table.find(ithkuil::v3::serialize5(in.begin(), in.end())); it != table.end())
					{
						state.valence_ = it->second;
						return true;
					}
					return false;
				}
			};

			template<>
			struct formative_action<cg>
			{
				template<typename ActionInput, typename... States>
				static bool apply(const ActionInput& in, formative_state& state, formative_tables& tables, States&&...)
				{
					const auto& table = tables.cg_map.left;
					if (auto it = table.find(ithkuil::v3::serialize5(in.begin(), in.end())); it != table.end())
					{
						state.validation_ = it->second;
						return true;
					}
					return false;
				}
			};

			template<>
			struct formative_action<cs>
			{
				template<typename ActionInput, typename... States>
				static bool apply(const ActionInput& in, formative_state& state, formative_tables& tables, States&&...)
				{
					const auto& table = tables.cs_map.left;
					if (auto it = table.find(ithkuil::v3::serialize5(in.begin(), in.end())); it != table.end())
					{
						std::tie(state.aspect_, state.mood_) = static_cast<v3::newslot::cs::value_t>(v3::newslot::cs(it->second));
						return true;
					}
					return false;
				}
			};

			template<>
			struct formative_action<vr>
			{
				template<typename ActionInput, typename... States>
				static bool apply(const ActionInput& in, formative_state& state, formative_tables& tables, States&&...)
				{
					const auto& table = tables.vr_map.left;
					if (auto it = table.find(ithkuil::v3::serialize5(in.begin(), in.end())); it != table.end())
					{
						state.vr_ = it->second;
						return true;
					}
					return false;
				}
			};

			template<>
			struct formative_action<vp>
			{
				template<typename ActionInput, typename... States>
				static bool apply(const ActionInput& in, formative_state& state, formative_tables& tables, States&&...)
				{
					const auto& table = tables.vp_map.left;
					if (auto it = table.find(ithkuil::v3::serialize5(in.begin(), in.end())); it != table.end())
					{
						state.vp_ = it->second;
						return true;
					}
					return false;
				}
			};

			template<>
			struct formative_action<ca>
			{
				template<typename ActionInput, typename... States>
				static bool apply(const ActionInput& in, formative_state& state, formative_tables& tables, States&&...)
				{
					const auto& table = tables.ca_map.left;
					if (auto it = table.find(ithkuil::v3::serialize5(in.begin(), in.end())); it != table.end())
					{
						state.ca_ = it->second;
						return true;
					}
					return false;
				}
			};

			template<>
			struct formative_action<vf>
			{
				template<typename ActionInput, typename... States>
				static bool apply(const ActionInput& in, formative_state& state, formative_tables& tables, States&&...)
				{
					const auto& table = tables.vf_map.left;
					if (auto it = table.find(ithkuil::v3::serialize5(in.begin(), in.end())); it != table.end())
					{
						state.vf_ = newslot::vf(it->second);
						return true;
					}
					return false;
				}
			};

			// cb su vx

			template<>
			struct formative_action<cb>
			{
				template<typename ActionInput, typename... States>
				static bool apply(const ActionInput& in, formative_state& state, formative_tables& tables, States&&...)
				{
					const auto& table = tables.cb_map.left;
					if (auto it = table.find(ithkuil::v3::serialize5(in.begin(), in.end())); it != table.end())
					{
						state.bias_ = it->second;
						return true;
					}
					return false;
				}
			};

			template<>
			struct formative_action<vx>
			{
				template<typename ActionInput, typename... States>
				static bool apply(const ActionInput& in, formative_state& state, formative_tables& tables, States&&...)
				{
					const auto& table = tables.vx_map.left;
					if (auto it = table.find(ithkuil::v3::serialize5(in.begin(), in.end())); it != table.end())
					{
						state.vx_ = v3::newslot::vx(it->second);
						return true;
					}
					return false;
				}
			};

			template<>
			struct formative_action<su>
			{
				template<typename ActionInput, typename... States>
				static bool apply(const ActionInput& in, formative_state& state, formative_tables& tables, States&&...)
				{
					const auto& table = tables.su_map.left;
					if (auto it = table.find(ithkuil::v3::serialize5(in.begin(), in.end())); it != table.end())
					{
						if (state.vx_)
						{
							const auto [t, d] = *state.vx_;
							state.vxc_.emplace_back(t, d, it->second);
							return true;
						}
					}
					return false;
				}
			};

			template<>
			struct formative_action<cr>
			{
				template<typename ActionInput, typename... States>
				static bool apply(const ActionInput& in, formative_state& state, formative_tables& tables, States&&...)
				{
					const auto& table = tables.cg_map.left;
					const auto rc = ithkuil::v3::serialize5(in.begin(), in.end());
					if (auto it = table.find(rc); it == table.end())
					{
						state.root_ = rc;
						return true;
					}
					return false;
				}
			};

			template<>
			struct formative_action<cx>
			{
				template<typename ActionInput, typename... States>
				static bool apply(const ActionInput& in, formative_state& state, formative_tables& tables, States&&...)
				{
					const auto& table = tables.cg_map.left;
					const auto rc = ithkuil::v3::serialize5(in.begin(), in.end());
					if (auto it = table.find(rc); it == table.end())
					{
						state.inc_root = rc;
						return true;
					}
					return false;
				}
			};

			template<>
			struct formative_action<vc>
			{
				template<typename ActionInput, typename... States>
				static bool apply(const ActionInput& in, formative_state& state, formative_tables& tables, States&&...)
				{

					std::vector<v3::irs::type> prepared(in.begin(), in.end());
					prepared.erase(std::remove(prepared.begin(), prepared.end(), irs::syllable_boundary_vc), prepared.end());
					if (prepared.size() == 2 && v3::ir::is_udiphtong(prepared[0]) && prepared[1] == v3::irs::u)
					{
						state.m = vc_mutation::u_intact;
					}
					else if (prepared.size() == 1 && ir::is_udiphtong(prepared[0]))
					{
						state.m = vc_mutation::u_mutated;
					}
					else if (prepared.size() == 2 && v3::ir::is_idiphtong(prepared[0]) && prepared[1] == v3::irs::i)
					{
						state.m = vc_mutation::i_diphtong;
					}
					auto glotstop = std::find(prepared.begin(), prepared.end(), v3::irs::glottal_stop);
					if (glotstop == prepared.end() || std::next(glotstop) == prepared.end())
					{
						const auto& table = tables.vc1_map.left;
						auto match = v3::slot::vc1_map.left.find(v3::serialize5(prepared.begin(), prepared.end()));
						if (auto it = table.find(ithkuil::v3::serialize5(prepared.begin(), prepared.end())); it != table.end())
						{
							state._case = it->second;
							if (state.m == vc_mutation::u_mutated)
							{
								prepared.push_back(v3::irs::u);
#pragma warning(suppress : 4456)
								if (auto it = table.find(ithkuil::v3::serialize5(prepared.begin(), prepared.end())); it != table.end())
								{
									state.cm = it->second;
								}
							}
							return true;
						}
					}
					else
					{
						const auto& table = tables.vc2_map.left;
						v3::newslot::vr _vr;
						if (auto it = table.find(ithkuil::v3::serialize5(prepared.begin(), std::next(glotstop))); it != table.end())
						{
							state._case = it->second;
#pragma warning(suppress : 4456)
							const auto& table = tables.vr_map.left;
#pragma warning(suppress : 4456)
							if (auto it = table.find(ithkuil::v3::serialize5(std::next(glotstop), prepared.end())); it != table.end())
							{
								// TODO
								const auto [s, p, f] = static_cast<v3::newslot::vr::value_t>(v3::newslot::vr(it->second));
								if ((s != 1 || p != 1 || f != function::stative) && state.vr_)
								{
									return false;
								}
								state.vr_ = it->second;
								return true;
							}
						}
					}

					return false;
				}
			};

			template<>
			struct formative_action<civi>
			{
				template<typename ActionInput, typename... States>
				static bool apply(const ActionInput& in, formative_state& state, formative_tables& tables, States&&...)
				{
					const auto& table = tables.civi_map.left;
					if (auto it = table.find(ithkuil::v3::serialize5(in.begin(), in.end())); it != table.end())
					{
						state.civi_ = it->second;
						return true;
					}
					return false;
				}
			};

			template<typename R>
			struct formative_control : pegtl::normal<R>
			{};

			template<>
			struct formative_control<f_0> : pegtl::normal<f_0>
			{
				template<typename ParseInput, typename... States>
				static void failure(const ParseInput&, formative_state& state, States&&...)
				{
					state = {};
				}
			};

			template<>
			struct formative_control<f_1> : pegtl::normal<f_1>
			{
				template<typename ParseInput, typename... States>
				static void failure(const ParseInput&, formative_state& state, States&&...)
				{
					state = {};
				}
			};

			template<>
			struct formative_control<f_pr> : pegtl::normal<f_pr>
			{
				template<typename ParseInput, typename... States>
				static void failure(const ParseInput&, formative_state& state, States&&...)
				{
					state = {};
				}
			};

			template<>
			struct formative_control<f_r> : pegtl::normal<f_r>
			{
				template<typename ParseInput, typename... States>
				static void failure(const ParseInput&, formative_state& state, States&&...)
				{
					state = {};
				}
			};

			template<>
			struct formative_control<f_p1> : pegtl::normal<f_p1>
			{
				template<typename ParseInput, typename... States>
				static void failure(const ParseInput&, formative_state& state, States&&...)
				{
					state = {};
				}
			};
		}
	}
}

struct formative
{
	ithkuil::v3::root_t _root;
	ithkuil::v3::stem_t _stem;
	ithkuil::v3::pattern_t _pattern;
	ithkuil::v3::configuration _configuration;
	ithkuil::v3::affiliation _affiliation;
	ithkuil::v3::perspective _perspective;
	ithkuil::v3::extension _extension;
	ithkuil::v3::essence _essence;
	ithkuil::v3::context _context;
	ithkuil::v3::designation _designation;
	ithkuil::v3::designation inc_designation;
	ithkuil::v3::case_ _case;
	ithkuil::v3::root_t inc_root;
	ithkuil::v3::stem_t inc_stem;
	ithkuil::v3::pattern_t inc_pattern;
	std::optional<std::tuple<ithkuil::v3::perspective, ithkuil::v3::configuration>> inc_pc;
	ithkuil::v3::function _function;
	ithkuil::v3::mood _mood;
	ithkuil::v3::illocution _illocution;
	ithkuil::v3::relation _relation;
	ithkuil::v3::phase _phase;
	ithkuil::v3::sanction _sanction;
	ithkuil::v3::valence _valence;
	ithkuil::v3::version _version;
	ithkuil::v3::validation _validation;
	ithkuil::v3::aspect _aspect;
	ithkuil::v3::format _format;
	ithkuil::v3::bias _bias;
	std::vector<ithkuil::v3::case_> inc_cases;
	std::vector<ithkuil::v3::vxc> _vxcs;
};

inline auto r2wstr(v3::root_t r)
{
	std::wstring strbuf;
	const auto [arr, count] = v3::deserialize5(r);
	for (unsigned char i = 0; i < count; i++)
	{
		strbuf += v3::ir::description[arr[i]];
	}
	return strbuf;
}

std::wstring f2wstr(const formative& f, bool full)
{
	auto rfind = [](const auto& map, const auto& value)
	{
		return std::find_if(std::begin(map), std::end(map), [value](auto kv)
			{
				return kv.second == value;
			})->first;
	};
	std::wstring strbuf;
	if (f._relation == v3::relation::unframed && full)
	{
		strbuf += L"UNFRAMED-";
	}
	else if (f._relation == v3::relation::framed)
	{
		strbuf += L"FRAMED-";
	}
	strbuf += rfind(v3::notation::function_map, f._function) + L"-";
	strbuf += r2wstr(f._root) + L"/S" + std::to_wstring(f._stem) + L"/P" + std::to_wstring(f._pattern) + L"/";
	strbuf += rfind(v3::notation::designation_map, f._designation);
	if (f._configuration != v3::configuration::uniplex || full)
	{
		strbuf += L"-";
		strbuf += rfind(v3::notation::configuration_map, f._configuration);
	}
	if (f._affiliation != v3::affiliation::consolidative || full)
	{
		strbuf += L"-";
		strbuf += rfind(v3::notation::affiliation_map, f._affiliation);
	}
	if (f._perspective != v3::perspective::monadic || full)
	{
		strbuf += L"-";
		strbuf += rfind(v3::notation::perspective_map, f._perspective);
	}
	if (f._extension != v3::extension::delimitive || full)
	{
		strbuf += L"-";
		strbuf += rfind(v3::notation::extension_map, f._extension);
	}
	if (f._essence != v3::essence::normal || full)
	{
		strbuf += L"-";
		strbuf += rfind(v3::notation::essence_map, f._essence);
	}
	if (f._context != v3::context::existential || full)
	{
		strbuf += L"-";
		strbuf += rfind(v3::notation::context_map, f._context);
	}
	strbuf += L"-" + rfind(v3::notation::case__map, f._case);
	if (f.inc_root != 0)
	{
		strbuf += L"-incorporated:" + r2wstr(f.inc_root) + L"/S" + std::to_wstring(f.inc_stem) + L"/P" + std::to_wstring(f.inc_pattern) + L"/";
		strbuf += rfind(v3::notation::designation_map, f.inc_designation);
		strbuf += L"/";
		if (f.inc_pc)
		{
			const auto [p, c] = *f.inc_pc;
			strbuf += rfind(v3::notation::configuration_map, c);
			strbuf += L"/";
			strbuf += rfind(v3::notation::perspective_map, p);
			strbuf += L"-";
			for (const auto k : f.inc_cases)
			{
				strbuf += rfind(v3::notation::case__map, k);
				strbuf += L"-";
			}
		}
		strbuf += rfind(v3::notation::format_map, f._format);
		strbuf += L":";
	}
	if (f._mood != v3::mood::factual || full)
	{
		strbuf += L"-";
		strbuf += rfind(v3::notation::mood_map, f._mood);
	}
	if (f._illocution != v3::illocution::assertive || full)
	{
		strbuf += L"-";
		strbuf += rfind(v3::notation::illocution_map, f._illocution);
	}
	if (f._phase != v3::phase::contextual || full)
	{
		strbuf += L"-";
		strbuf += rfind(v3::notation::phase_map, f._phase);
	}
	if (f._sanction != v3::sanction::propositional || full)
	{
		strbuf += L"-";
		strbuf += rfind(v3::notation::sanction_map, f._sanction);
	}
	if (f._valence != v3::valence::monoactive || full)
	{
		strbuf += L"-";
		strbuf += rfind(v3::notation::valence_map, f._valence);
	}
	if (f._validation != v3::validation::confirmative || full)
	{
		strbuf += L"-";
		strbuf += rfind(v3::notation::validation_map, f._validation);
	}
	if (f._aspect != v3::aspect::none || full)
	{
		strbuf += L"-";
		strbuf += rfind(v3::notation::aspect_map, f._aspect);
	}
	if (f._version != v3::version::processual || full)
	{
		strbuf += L"-";
		strbuf += rfind(v3::notation::version_map, f._version);
	}
	for (const auto& suffix : f._vxcs)
	{
		strbuf += L"-";
		strbuf += rfind(v3::notation::suffix_map, suffix._suffix);
		strbuf += L"/";
		strbuf += std::to_wstring(suffix._type);
		strbuf += L"/";
		strbuf += std::to_wstring(suffix._degree);
	}
	if (f._bias != v3::bias::none)
	{
		strbuf += L"-";
		strbuf += rfind(v3::notation::bias_map, f._bias);
	}
	return strbuf;
}

int wmain(int, wchar_t* [], wchar_t* [])
{
	std::wstring form = fmt::format(L"{}", L"");
	auto rfind = [](const auto& map, const auto& value)
	{
		return std::find_if(std::begin(map), std::end(map), [value](auto kv)
			{
				return kv.second == value;
			})->first;
	};
	{
		std::ifstream output(R"(ithkuil_cv.dat)", std::ios::binary);
		boost::archive::binary_iarchive out(output);
		out >> v3::slot::cv_map;
	}
	{
		std::ifstream output(R"(ithkuil_vl.dat)", std::ios::binary);
		boost::archive::binary_iarchive out(output);
		out >> v3::slot::vl_map;
	}
	{
		std::ifstream output(R"(ithkuil_cg.dat)", std::ios::binary);
		boost::archive::binary_iarchive out(output);
		out >> v3::slot::cg_map;
	}
	{
		std::ifstream output(R"(ithkuil_cs.dat)", std::ios::binary);
		boost::archive::binary_iarchive out(output);
		out >> v3::slot::cs_map;
	}
	{
		std::ifstream output(R"(ithkuil_vr.dat)", std::ios::binary);
		boost::archive::binary_iarchive out(output);
		out >> v3::slot::vr_map;
	}
	{
		std::ifstream output(R"(ithkuil_vp.dat)", std::ios::binary);
		boost::archive::binary_iarchive out(output);
		out >> v3::slot::vp_map;
	}
	{
		std::ifstream output(R"(ithkuil_ca.dat)", std::ios::binary);
		boost::archive::binary_iarchive out(output);
		out >> v3::slot::ca_map;
	}
	{
		std::ifstream output(R"(ithkuil_vf.dat)", std::ios::binary);
		boost::archive::binary_iarchive out(output);
		out >> v3::slot::vf_map;
	}
	{
		std::ifstream output(R"(ithkuil_cb.dat)", std::ios::binary);
		boost::archive::binary_iarchive out(output);
		out >> v3::slot::cb_map;
	}
	{
		std::ifstream output(R"(ithkuil_su.dat)", std::ios::binary);
		boost::archive::binary_iarchive out(output);
		out >> v3::slot::su_map;
	}
	{
		std::ifstream output(R"(ithkuil_vx.dat)", std::ios::binary);
		boost::archive::binary_iarchive out(output);
		out >> v3::slot::vx_map;
	}
	{
		std::ifstream output(R"(ithkuil_vc1.dat)", std::ios::binary);
		boost::archive::binary_iarchive out(output);
		out >> v3::slot::vc1_map;
	}
	{
		std::ifstream output(R"(ithkuil_vc2.dat)", std::ios::binary);
		boost::archive::binary_iarchive out(output);
		out >> v3::slot::vc2_map;
	}
	{
		std::ifstream output(R"(ithkuil_civi.dat)", std::ios::binary);
		boost::archive::binary_iarchive out(output);
		out >> v3::slot::civi_map;
	}

	std::wstring xstr;
	while (std::getline(std::wcin, xstr, L'\n'))
	{
		boost::bimap<uint_fast32_t, std::byte> x;
		std::wstring st;
		//utf8::utf8to16(xstr.begin(), xstr.end(), std::back_inserter(st));
		//std::u16string xdd = utf8::utf8to16(xstr);
		std::vector<boost::iterator_range<std::wstring::iterator>> parts;
		boost::algorithm::split(parts, xstr, boost::is_any_of(L" ,\t."), boost::token_compress_on);
		std::wostringstream nuf;
		if (parts.size() < 1)
		{
			std::wcout << L"Provide formative" << std::endl;
			continue;
		}
		std::wstring str(parts[0].begin(), parts[0].end());
		v3::pegtl_grammar::formative_tables tables
		{
			.cv_map = ithkuil::v3::slot::cv_map,
			.vl_map = ithkuil::v3::slot::vl_map,
			.cg_map = ithkuil::v3::slot::cg_map,
			.cs_map = ithkuil::v3::slot::cs_map,
			.vr_map = ithkuil::v3::slot::vr_map,
			.vp_map = ithkuil::v3::slot::vp_map,
			.ca_map = ithkuil::v3::slot::ca_map,
			.vf_map = ithkuil::v3::slot::vf_map,
			.cb_map = ithkuil::v3::slot::cb_map,
			.su_map = ithkuil::v3::slot::su_map,
			.vx_map = ithkuil::v3::slot::vx_map,
			.vc1_map = ithkuil::v3::slot::vc1_map,
			.vc2_map = ithkuil::v3::slot::vc2_map,
			.civi_map = ithkuil::v3::slot::civi_map
		};
		v3::pegtl_grammar::formative_state xxx {};
		auto [phs, unstressed, diacriticized, stressed, syllable, tone] = v3::ir::to_irs(str);
		syllable -= 1;
		try
		{
			pegtl::memory_input input(reinterpret_cast<const char*>(phs.data()), phs.size(), "yser data");
			try
			{
				bool is_parsed = pegtl::parse<v3::pegtl_grammar::f_rule, v3::pegtl_grammar::formative_action, v3::pegtl_grammar::formative_control>(input, xxx, tables);
				if (is_parsed)
				{
					formative f = {};
					switch (tone)
					{
					case v3::ir::tone_t::falling:
						f._version = v3::version::processual;
						break;
					case v3::ir::tone_t::rising:
						f._version = v3::version::ineffectual;
						break;
					case v3::ir::tone_t::low:
						f._version = v3::version::incompletive;
						break;
					case v3::ir::tone_t::high:
						f._version = v3::version::completive;
						break;
					case v3::ir::tone_t::falling_rising:
						f._version = v3::version::effective;
						break;
					case v3::ir::tone_t::rising_falling:
						f._version = v3::version::positive;
						break;
					default:
						nuf << L"tone error" << std::endl;
						continue;
					}
					v3::ir::stress stress = {};
					bool stress_error = false;
					if (stressed == 0 && unstressed.empty()) // penultimate
					{
						stress = v3::ir::stress::penultimate;
					}
					else if (stressed != 0) // explicitly marked stress
					{
						switch (syllable - stressed)
						{
						case 0: // ultimate
							stress = v3::ir::stress::ultimate;
							break;
						case 1:
							stress = v3::ir::stress::penultimate;
							stress_error = true;
							break;
						case 2:
							stress = v3::ir::stress::antepenultimate;
							break;
						case 3:
							stress = v3::ir::stress::preantepenultimate;
							break;
						default:
							stress = v3::ir::stress::penultimate;
							nuf << L"erroneus stress mark: assuming penultimate. ";
							stress_error = true;
						}
					}
					else
					{
						if (std::find(diacriticized.begin(), diacriticized.end(), syllable) != diacriticized.end()
							&& std::find(unstressed.begin(), unstressed.end(), syllable - 1) != unstressed.end()
							|| std::find(unstressed.begin(), unstressed.end(), syllable - 2) != unstressed.end()
							&& std::find(diacriticized.begin(), diacriticized.end(), syllable - 1) != diacriticized.end()) // ultimate
						{
							stress = v3::ir::stress::ultimate;
						}
						else if (std::find(diacriticized.begin(), diacriticized.end(), syllable - 2) != diacriticized.end() && std::find(unstressed.begin(), unstressed.end(), syllable - 2) == unstressed.end())
						{
							stress = v3::ir::stress::antepenultimate;
						}
						else if (std::find(diacriticized.begin(), diacriticized.end(), syllable - 3) != diacriticized.end() && std::find(unstressed.begin(), unstressed.end(), syllable - 3) == unstressed.end())
						{
							stress = v3::ir::stress::preantepenultimate;
						}
					}
					switch (stress)
					{
					case v3::ir::stress::penultimate:
						f._designation = v3::designation::informal;
						f._relation = v3::relation::unframed;
						break;
					case v3::ir::stress::ultimate:
						f._designation = v3::designation::formal;
						f._relation = v3::relation::unframed;
						break;
					case v3::ir::stress::antepenultimate:
						f._designation = v3::designation::informal;
						f._relation = v3::relation::framed;
						break;
					case v3::ir::stress::preantepenultimate:
						f._designation = v3::designation::formal;
						f._relation = v3::relation::framed;
						break;
					}
					f._root = xxx.root_;
					f.inc_root = xxx.inc_root.value_or(0);
					f._case = xxx._case;
					f._phase = xxx.phase_.value_or(v3::phase::contextual);
					f._sanction = xxx.sanction_.value_or(v3::sanction::propositional);
					f._illocution = xxx.illocution_.value_or(v3::illocution::assertive);
					if (xxx.ca_)
					{
						std::tie(f._configuration, f._affiliation, f._perspective, f._extension, f._essence) = static_cast<v3::newslot::ca::value_t>(v3::newslot::ca(*xxx.ca_));
					}
					else
					{
						nuf << L"PARSING FAILED (no ca)" << std::endl;
						continue;
					}
					if (xxx.vf_ || xxx.inc_pc)
					{
						const auto [c, format] = xxx.vf_.value_or(std::make_tuple(v3::context::existential, v3::format::none));
						f.inc_pc = xxx.inc_pc;
						f.inc_cases = std::move(xxx.inc_cases);
						f._context = c;
						f._format = format;
					}
					f._bias = xxx.bias_.value_or(v3::bias::none);
					f._vxcs = std::move(xxx.vxc_);
					if (xxx.vr_)
					{
						std::tie(f._stem, f._pattern, f._function) = static_cast<v3::newslot::vr::value_t>(v3::newslot::vr(*xxx.vr_));
					}
					else
					{
						f._pattern = 1;
						f._stem = 1;
						f._function = v3::function::stative;
					}
					if (xxx.vp_)
					{
						std::tie(f.inc_stem, f.inc_pattern, f.inc_designation) = static_cast<v3::newslot::vp::value_t>(v3::newslot::vp(*xxx.vp_));
					}
					if (xxx.civi_)
					{
						std::tie(f._mood, f._illocution, std::ignore) = static_cast<v3::newslot::civi::value_t>(v3::newslot::civi(*xxx.civi_));
					}
					f._valence = xxx.valence_.value_or(v3::valence::monoactive);
					f._validation = xxx.validation_.value_or(v3::validation::confirmative);
					f._aspect = xxx.aspect_.value_or(v3::aspect::none);



					nuf << f2wstr(f, false) << std::endl;
					//std::wcout << f2wstr(f, true) << std::endl;
					//std::wcout << L"\t" << rfind(v3::notation::phase_map, *xxx.phase_) << L"\t" << rfind(v3::notation::sanction_map, *xxx.sanction_) << L"\t" << rfind(v3::notation::illocution_map, *xxx.illocution_) << std::endl;
				}
				else
				{
					nuf << L"PARSING FAILED" << std::endl;
				}
			}
			catch (const pegtl::parse_error& e)
			{
				nuf << L"BAD HAPPENED" << std::endl;
			}
		}
		catch (const std::exception& e)
		{

			// Generic catch block for other exceptions
			nuf << L"BAD HAPPENED" << std::endl;

		}
		std::wstring rsp = nuf.str();
		std::string rsp2;
		//utf8::utf16to8(rsp.begin(), rsp.end(), std::back_inserter(rsp2));
		std::wcout << rsp;
	}
}
