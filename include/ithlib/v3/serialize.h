//#pragma once
//#include <stdexcept>
//#include <type_traits>
//#include <tuple>
//#include <optional>
//
//#include "morphology.h"
//#include "ir.h"
//
//namespace ithkuil
//{
//	namespace v3
//	{
//		class serialization_exception : public std::invalid_argument
//		{
//			using std::invalid_argument::invalid_argument;
//		};
//
//		using serialized_t = unsigned int;
//		constexpr int serialization_shift = 6;
//		constexpr serialized_t serialization_mask = (1u << 6) - 1;
//
//		template<typename Iterator>
//		auto serialize5(Iterator first, Iterator last) -> serialized_t
//		{
//			serialized_t serialized = 0;
//
//			if (last - first > 5)
//			{
//				return 0;
//			}
//
//			if (first == last)
//				return serialized;
//			for (serialized = static_cast<serialized_t>(static_cast<irs::type>(*first++)); first != last; ++first)
//			{
//				serialized <<= serialization_shift;
//				serialized |= static_cast<serialized_t>(static_cast<irs::type>(*first));
//			}
//			return serialized;
//		}
//
//		template<typename T, size_t N>
//		auto serialize5(const T(&arr)[N]) -> serialized_t
//		{
//			serialized_t serialized = static_cast<serialized_t>(static_cast<irs::type>(arr[0]));
//			unsigned int i = 1;
//			for (; i < N && arr[i] != irs::void_; ++i)
//			{
//				serialized <<= serialization_shift;
//				serialized |= static_cast<serialized_t>(static_cast<irs::type>(arr[i]));
//			}
//			if (i > 6)
//			{
//				return 0;
//			}
//			return serialized;
//		}
//
//		template<typename T>
//		auto serialize5(const std::vector<T>& vec) -> serialized_t
//		{
//			return serialize5(vec.begin(), vec.end());
//		}
//
//		inline auto deserialize5(serialized_t a) noexcept -> std::pair<std::array<irs::type, 5>, unsigned char>
//		{
//			unsigned char count = 0;
//			std::array<irs::type, 5> deserialized;
//
//			while (a != irs::void_)
//			{
//				deserialized[count++] = static_cast<irs::type>(a & serialization_mask);
//				a >>= serialization_shift;
//			}
//
//			std::reverse(&deserialized[0], &deserialized[count]);
//
//			return { deserialized, count };
//		}
//
//		using serialized_ca_t = unsigned int;
//
//		inline auto serialize_ca(configuration c, affiliation f, perspective p, extension ex, essence es) noexcept -> serialized_ca_t
//		{
//			serialized_ca_t serialized = 0;
//
//			serialized |= static_cast<serialized_ca_t>(c);
//			serialized <<= 2;
//			serialized |= static_cast<serialized_ca_t>(f);
//			serialized <<= 2;
//			serialized |= static_cast<serialized_ca_t>(p);
//			serialized <<= 3;
//			serialized |= static_cast<serialized_ca_t>(ex);
//			serialized <<= 1;
//			serialized |= static_cast<serialized_ca_t>(es);
//			return serialized;
//		}
//
//		inline auto deserialize_ca(serialized_ca_t serialized) noexcept -> std::tuple<configuration, affiliation, perspective, extension, essence>
//		{
//			configuration c;
//			affiliation f;
//			perspective p;
//			extension ex;
//			essence es;
//
//			es = static_cast<essence>(serialized & 1);
//			serialized >>= 1;
//			ex = static_cast<extension>(serialized & 7);
//			serialized >>= 3;
//			p = static_cast<perspective>(serialized & 3);
//			serialized >>= 2;
//			f = static_cast<affiliation>(serialized & 3);
//			serialized >>= 2;
//			c = static_cast<configuration>(serialized & 15);
//			return { c, f, p, ex, es };
//		}
//
//		using serialized_cv_t = unsigned int;
//
//		inline auto serialize_cv(phase p, sanction s, illocution i) noexcept -> serialized_cv_t
//		{
//			serialized_cv_t serialized = 0;
//
//			serialized |= static_cast<serialized_cv_t>(p);
//			serialized <<= 4;
//			serialized |= static_cast<serialized_cv_t>(s);
//			serialized <<= 3;
//			serialized |= static_cast<serialized_cv_t>(i);
//			return serialized;
//		}
//
//		inline auto deserialize_cv(serialized_cv_t serialized) noexcept-> std::tuple<phase, sanction, illocution>
//		{
//			phase p;
//			sanction s;
//			illocution i;
//
//			i = static_cast<illocution>(serialized & 7);
//			serialized >>= 3;
//			s = static_cast<sanction>(serialized & 15);
//			serialized >>= 4;
//			p = static_cast<phase>(serialized & 15);
//			return { p, s, i };
//		}
//
//		using serialized_cs_t = unsigned int;
//
//		inline auto serialize_cs(aspect a, mood m) noexcept -> serialized_cs_t
//		{
//			serialized_cs_t serialized = 0;
//
//			serialized |= static_cast<serialized_cs_t>(a);
//			serialized <<= 3;
//			serialized |= static_cast<serialized_cs_t>(m);
//			return serialized;
//		}
//
//		inline auto deserialize_cs(serialized_cs_t serialized) noexcept -> std::tuple<aspect, mood>
//		{
//			aspect a;
//			mood m;
//
//			m = static_cast<mood>(serialized & 7);
//			serialized >>= 3;
//			a = static_cast<aspect>(serialized & 63);
//			return { a, m };
//		}
//
//		using serialized_vr_t = unsigned int;
//
//		inline auto serialize_vr(stem_t s, pattern_t p, function f) noexcept -> serialized_vr_t
//		{
//			serialized_vr_t serialized = 0;
//
//			serialized |= static_cast<serialized_vr_t>(s);
//			serialized <<= 2;
//			serialized |= static_cast<serialized_vr_t>(p);
//			serialized <<= 2;
//			serialized |= static_cast<serialized_vr_t>(f);
//			return serialized;
//		}
//
//		inline auto deserialize_vr(serialized_vr_t serialized) noexcept -> std::tuple<stem_t, pattern_t, function>
//		{
//			stem_t s;
//			pattern_t p;
//			function f;
//
//			f = static_cast<function>(serialized & 3);
//			serialized >>= 2;
//			p = static_cast<pattern_t>(serialized & 3);
//			serialized >>= 2;
//			s = static_cast<stem_t>(serialized & 3);
//			return { s, p, f };
//		}
//
//		using serialized_vp_t = unsigned int;
//
//		inline auto serialize_vp(stem_t s, pattern_t p, designation d) noexcept -> serialized_vp_t
//		{
//			serialized_vp_t serialized = 0;
//
//			serialized |= static_cast<serialized_vp_t>(s);
//			serialized <<= 2;
//			serialized |= static_cast<serialized_vp_t>(p);
//			serialized <<= 1;
//			serialized |= static_cast<serialized_vp_t>(d);
//			return serialized;
//		}
//
//		inline auto deserialize_vp(serialized_vp_t serialized) noexcept -> std::tuple<stem_t, pattern_t, designation>
//		{
//			stem_t s;
//			pattern_t p;
//			designation d;
//
//			d = static_cast<designation>(serialized & 1);
//			serialized >>= 1;
//			p = static_cast<pattern_t>(serialized & 3);
//			serialized >>= 2;
//			s = static_cast<stem_t>(serialized & 3);
//			return { s, p, d };
//		}
//
//		using serialized_vf_t = unsigned int;
//
//		inline auto serialize_vf(context c, format_t f) noexcept -> serialized_vf_t
//		{
//			serialized_vf_t serialized = 0;
//
//			serialized |= static_cast<serialized_vf_t>(c);
//			serialized <<= 4;
//			serialized |= static_cast<serialized_vf_t>(f);
//			return serialized;
//		}
//
//		inline auto deserialize_vf(serialized_vf_t serialized) noexcept -> std::tuple<context, format_t>
//		{
//			context c;
//			format_t f;
//
//			f = static_cast<format_t>(serialized & 15);
//			serialized >>= 4;
//			c = static_cast<context>(serialized & 3);
//			return { c, f };
//		}
//
//		using serialized_vx_t = unsigned int;
//
//		inline auto serialize_vx(type_t t, degree_t d) noexcept -> serialized_vx_t
//		{
//			serialized_vx_t serialized = 0;
//
//			serialized |= static_cast<serialized_vx_t>(t);
//			serialized <<= 4;
//			serialized |= static_cast<serialized_vx_t>(d);
//			return serialized;
//		}
//
//		inline auto deserialize_vx(serialized_vx_t serialized) noexcept -> std::tuple<type_t, degree_t>
//		{
//			type_t t;
//			degree_t d;
//
//			d = static_cast<degree_t>(serialized & 15);
//			serialized >>= 4;
//			t = static_cast<type_t>(serialized & 3);
//			return { t, d };
//		}
//
//		using serialized_vc_t = unsigned int;
//
//		inline auto serialize_vc(case_ c, std::optional<serialized_vr_t> v, vc_mutation mutated) noexcept -> serialized_vc_t
//		{
//			serialized_vc_t serialized = 0;
//			serialized |= static_cast<serialized_vc_t>(c);
//			serialized <<= 6;
//			if (v)
//			{
//				serialized |= static_cast<serialized_vc_t>(v.value());
//			}
//			serialized <<= 2;
//			serialized |= static_cast<serialized_vc_t>(mutated);
//			return serialized;
//		}
//
//		inline auto deserialize_vc(serialized_vc_t serialized) noexcept -> std::tuple<case_, std::optional<serialized_vr_t>, vc_mutation>
//		{
//			case_ c;
//			std::optional<serialized_vr_t> v;
//			vc_mutation mutated;
//
//			mutated = static_cast<vc_mutation>(serialized & 3);
//			serialized >>= 2;
//			c = static_cast<case_>((serialized >> 6) & 127);
//			if (static_cast<std::underlying_type_t<case_>>(c) >= static_cast<std::underlying_type_t<case_>>(v3::case_::simultaneitive)
//				&& static_cast<std::underlying_type_t<case_>>(c) <= static_cast<std::underlying_type_t<case_>>(v3::case_::navigative))
//			{
//				v = static_cast<serialized_vr_t>(serialized & 63);
//			}
//
//			return { c, v, mutated };
//		}
//
//		using serialized_civi_t = unsigned int;
//
//		inline auto serialize_civi(mood m, illocution i, civi_mutation mutated) noexcept -> serialized_civi_t
//		{
//			serialized_civi_t serialized = 0;
//
//			serialized |= static_cast<serialized_civi_t>(m);
//			serialized <<= 3;
//			serialized |= static_cast<serialized_civi_t>(i);
//			serialized <<= 2;
//			serialized |= static_cast<serialized_civi_t>(mutated);
//			return serialized;
//		}
//
//		inline auto deserialize_civi(serialized_civi_t serialized) noexcept -> std::tuple<mood, illocution, civi_mutation>
//		{
//			mood m;
//			illocution i;
//			civi_mutation mutated;
//
//			mutated = static_cast<civi_mutation>(serialized & 3);
//			serialized >>= 2;
//			i = static_cast<illocution>(serialized & 7);
//			serialized >>= 3;
//			m = static_cast<mood>(serialized & 7);
//			return { m , i, mutated };
//		}
//
//		namespace newslot
//		{
//			class cv
//			{
//			public:
//				using packed_t = unsigned int;
//				using value_t = std::tuple<phase, sanction, illocution>;
//				packed_t value = 0;
//				constexpr cv() noexcept = default;
//
//				constexpr cv(packed_t value) noexcept
//					: value(value)
//				{				}
//
//				constexpr cv(value_t value) noexcept
//					: value(static_cast<packed_t>(std::get<2>(value))
//						| (static_cast<packed_t>(std::get<1>(value)) << 3)
//						| (static_cast<packed_t>(std::get<0>(value)) << 7))
//				{				}
//
//				constexpr operator packed_t() const noexcept
//				{
//					return value;
//				}
//
//				constexpr operator value_t() const noexcept
//				{
//					return { static_cast<phase>((value >> 7) & 15), static_cast<sanction>((value >> 3) & 15), static_cast<illocution>(value & 7) };
//				}
//			};
//
//			class ca
//			{
//			public:
//				using packed_t = unsigned int;
//				using value_t = std::tuple<configuration, affiliation, perspective, extension, essence>;
//				packed_t value = 0;
//				constexpr ca() noexcept = default;
//
//				constexpr ca(packed_t value) noexcept
//					: value(value)
//				{				}
//
//				constexpr ca(value_t value) noexcept
//					: value(static_cast<packed_t>(std::get<4>(value))
//						| (static_cast<packed_t>(std::get<3>(value)) << 1)
//						| (static_cast<packed_t>(std::get<2>(value)) << 4)
//						| (static_cast<packed_t>(std::get<1>(value)) << 6)
//						| (static_cast<packed_t>(std::get<0>(value)) << 8))
//				{				}
//
//				constexpr operator packed_t() const noexcept
//				{
//					return value;
//				}
//
//				constexpr operator value_t() const noexcept
//				{
//					auto v = value;
//					configuration c = {};
//					affiliation f = {};
//					perspective p = {};
//					extension ex = {};
//					essence es = {};
//
//					es = static_cast<essence>(v & 1);
//					v >>= 1;
//					ex = static_cast<extension>(v & 7);
//					v >>= 3;
//					p = static_cast<perspective>(v & 3);
//					v >>= 2;
//					f = static_cast<affiliation>(v & 3);
//					v >>= 2;
//					c = static_cast<configuration>(v & 15);
//					return { c, f, p, ex, es };
//				}
//			};
//
//			class cs
//			{
//			public:
//				using packed_t = unsigned int;
//				using value_t = std::tuple<aspect, mood>;
//				packed_t packed = 0;
//				constexpr cs() noexcept = default;
//
//				constexpr cs(packed_t value) noexcept
//					: packed(value)
//				{				}
//
//				constexpr cs(value_t value) noexcept
//				{
//					packed |= static_cast<packed_t>(std::get<0>(value));
//					packed <<= 3;
//					packed |= static_cast<packed_t>(std::get<1>(value));
//				}
//
//				constexpr operator packed_t() const noexcept
//				{
//					return packed;
//				}
//
//				constexpr operator value_t() const noexcept
//				{
//					auto pck = packed;
//					aspect a = {};
//					mood m = {};
//
//					m = static_cast<mood>(pck & 7);
//					pck >>= 3;
//					a = static_cast<aspect>(pck & 63);
//					return { a, m };
//				}
//			};
//
//			class vr
//			{
//			public:
//				using packed_t = unsigned int;
//				using value_t = std::tuple<stem_t, pattern_t, function>;
//				packed_t packed = 0;
//				constexpr vr() noexcept = default;
//
//				constexpr vr(packed_t packed) noexcept
//					: packed(packed)
//				{				}
//
//				constexpr vr(value_t value) noexcept
//				{
//					auto [s, p, f] = value;
//					packed |= static_cast<packed_t>(s);
//					packed <<= 2;
//					packed |= static_cast<packed_t>(p);
//					packed <<= 2;
//					packed |= static_cast<packed_t>(f);
//				}
//
//				constexpr operator packed_t() const noexcept
//				{
//					return packed;
//				}
//
//				constexpr operator value_t() const noexcept
//				{
//					auto pck = packed;
//					stem_t s = {};
//					pattern_t p = {};
//					function f = {};
//
//					f = static_cast<function>(pck & 3);
//					pck >>= 2;
//					p = static_cast<pattern_t>(pck & 3);
//					pck >>= 2;
//					s = static_cast<stem_t>(pck & 3);
//					return { s, p, f };
//				}
//			};
//
//			class vp
//			{
//			public:
//				using packed_t = unsigned int;
//				using value_t = std::tuple<stem_t, pattern_t, designation>;
//				packed_t packed = 0;
//				constexpr vp() noexcept = default;
//
//				constexpr vp(packed_t packed) noexcept
//					: packed(packed)
//				{				}
//
//				constexpr vp(value_t value) noexcept
//				{
//					auto [s, p, d] = value;
//					packed |= static_cast<packed_t>(s);
//					packed <<= 2;
//					packed |= static_cast<packed_t>(p);
//					packed <<= 1;
//					packed |= static_cast<packed_t>(d);
//				}
//
//				constexpr operator packed_t() const noexcept
//				{
//					return packed;
//				}
//
//				constexpr operator value_t() const noexcept
//				{
//					auto pck = packed;
//					stem_t s = {};
//					pattern_t p = {};
//					designation d = {};
//
//					d = static_cast<designation>(pck & 1);
//					pck >>= 1;
//					p = static_cast<pattern_t>(pck & 3);
//					pck >>= 2;
//					s = static_cast<stem_t>(pck & 3);
//					return { s, p, d };
//				}
//			};
//
//			class vf
//			{
//			public:
//				using packed_t = unsigned int;
//				using value_t = std::tuple<context, format_t>;
//				packed_t packed = 0;
//				constexpr vf() noexcept = default;
//
//				constexpr vf(packed_t packed) noexcept
//					: packed(packed)
//				{				}
//
//				constexpr vf(value_t value) noexcept
//				{
//					auto [c, f] = value;
//					packed |= static_cast<packed_t>(c);
//					packed <<= 4;
//					packed |= static_cast<packed_t>(f);
//				}
//
//				constexpr operator packed_t() const noexcept
//				{
//					return packed;
//				}
//
//				constexpr operator value_t() const noexcept
//				{
//					auto pck = packed;
//					context c = {};
//					format_t f = {};
//
//					f = static_cast<format_t>(pck & 15);
//					pck >>= 4;
//					c = static_cast<context>(pck & 3);
//					return { c, f };
//				}
//			};
//
//			class vx
//			{
//			public:
//				using packed_t = unsigned int;
//				using value_t = std::tuple<type_t, degree_t>;
//				packed_t packed = 0;
//				constexpr vx() noexcept = default;
//
//				constexpr vx(packed_t packed) noexcept
//					: packed(packed)
//				{				}
//
//				constexpr vx(value_t value) noexcept
//				{
//					auto [t, d] = value;
//					packed |= static_cast<packed_t>(t);
//					packed <<= 4;
//					packed |= static_cast<packed_t>(d);
//				}
//
//				constexpr operator packed_t() const noexcept
//				{
//					return packed;
//				}
//
//				constexpr operator value_t() const noexcept
//				{
//					auto pck = packed;
//					type_t t = {};
//					degree_t d = {};
//
//					d = static_cast<degree_t>(pck & 15);
//					pck >>= 4;
//					t = static_cast<type_t>(pck & 3);
//					return { t, d };
//				}
//			};
//
//			class vc
//			{
//			public:
//				using packed_t = unsigned int;
//				using value_t = std::tuple<case_, std::optional<vr>, vc_mutation>;
//				packed_t packed = 0;
//				constexpr vc() noexcept = default;
//
//				constexpr vc(packed_t packed) noexcept
//					: packed(packed)
//				{				}
//
//				constexpr vc(value_t value) noexcept
//				{
//					auto [c, v, mutated] = value;
//					packed |= static_cast<packed_t>(c);
//					packed <<= 6;
//					if (v)
//					{
//						packed |= static_cast<packed_t>(v.value());
//					}
//					packed <<= 2;
//					packed |= static_cast<packed_t>(mutated);
//				}
//
//				constexpr operator packed_t() const noexcept
//				{
//					return packed;
//				}
//
//				constexpr operator value_t() const noexcept
//				{
//					auto pck = packed;
//					case_ c = {};
//					std::optional<packed_t> v = {};
//					vc_mutation mutated = {};
//
//					mutated = static_cast<vc_mutation>(pck & 3);
//					pck >>= 2;
//					c = static_cast<case_>((packed >> 6) & 127);
//					if (static_cast<std::underlying_type_t<case_>>(c) >= static_cast<std::underlying_type_t<case_>>(v3::case_::simultaneitive)
//						&& static_cast<std::underlying_type_t<case_>>(c) <= static_cast<std::underlying_type_t<case_>>(v3::case_::navigative))
//					{
//						v = static_cast<packed_t>(pck & 63);
//					}
//
//					return { c, v, mutated };
//				}
//			};
//
//			class civi
//			{
//			public:
//				using packed_t = unsigned int;
//				using value_t = std::tuple<mood, illocution, civi_mutation>;
//				packed_t packed = 0;
//				constexpr civi() noexcept = default;
//
//				constexpr civi(packed_t packed) noexcept
//					: packed(packed)
//				{				}
//
//				constexpr civi(value_t value) noexcept
//				{
//					auto [m, i, mutated] = value;
//					packed |= static_cast<packed_t>(m);
//					packed <<= 3;
//					packed |= static_cast<packed_t>(i);
//					packed <<= 2;
//					packed |= static_cast<packed_t>(mutated);
//				}
//
//				constexpr operator packed_t() const noexcept
//				{
//					return packed;
//				}
//
//				constexpr operator value_t() const noexcept
//				{
//					auto pck = packed;
//					mood m = {};
//					illocution i = {};
//					civi_mutation mutated = {};
//
//					mutated = static_cast<civi_mutation>(pck & 3);
//					pck >>= 2;
//					i = static_cast<illocution>(pck & 7);
//					pck >>= 3;
//					m = static_cast<mood>(pck & 7);
//					return { m , i, mutated };
//				}
//			};
//		}
//	}
//}
