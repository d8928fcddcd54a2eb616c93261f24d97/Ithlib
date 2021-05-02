#pragma once

#include <type_traits>
#include <tuple>
#include <vector>
#include <string_view>
#include <iostream>

static unsigned int i222 = 0;

namespace ithkuil
{
	namespace v3
	{
		namespace irs
		{
			enum _enum : unsigned char
			{
				void_,
				none,
				// consonants
				b,
				c,
				c_h,
				c_eject,
				c_caron,
				c_caron_h,
				c_caron_eject,
				c_cedilla,
				d,
				dh,
				f,
				g,
				h,
				j,
				k,
				k_h,
				k_eject,
				l,
				l_cedilla,
				m,
				n,
				n_caron,
				p,
				p_h,
				p_eject,
				q,
				q_h,
				q_eject,
				r,
				r_caron,
				s,
				s_caron,
				t,
				t_h,
				t_eject,
				t_cedilla,
				v,
				w,
				x,
				xh,
				y,
				z,
				z_overdot,
				z_caron,
				glottal_stop,
				// vowels
				a,
				a_circumflex,
				e,
				e_circumflex,
				e_diaeresis,
				i,
				i_circumflex,
				o,
				o_circumflex,
				o_diaeresis,
				u,
				u_circumflex,
				u_diaeresis,
				// miscellaneous
				syllable_boundary,
				syllable_boundary_vc
			};

			using type = std::underlying_type_t<_enum>;
		}
		namespace ir
		{
			inline const wchar_t* description[] =
			{
				L"!",
				L"*",
				L"b",
				L"c",
				L"cʰ",
				L"c’",
				L"č",
				L"čʰ",
				L"č’",
				L"ç",
				L"d",
				L"dh",
				L"f",
				L"g",
				L"h",
				L"j",
				L"k",
				L"kʰ",
				L"k’",
				L"l",
				L"ļ",
				L"m",
				L"n",
				L"ň",
				L"p",
				L"pʰ",
				L"p’",
				L"q",
				L"qʰ",
				L"q’",
				L"r",
				L"ř",
				L"s",
				L"š",
				L"t",
				L"tʰ",
				L"t’",
				L"ţ",
				L"v",
				L"w",
				L"x",
				L"xh",
				L"y",
				L"z",
				L"ż",
				L"ž",
				L"’",
				L"a",
				L"â",
				L"e",
				L"ê",
				L"ë",
				L"i",
				L"î",
				L"o",
				L"ô",
				L"ö",
				L"u",
				L"û",
				L"ü",
				L"-",
				L"="
			};

			inline auto is_vowel(irs::type ph) -> bool
			{
				switch (ph)
				{
				case irs::a:
				case irs::a_circumflex:
				case irs::e:
				case irs::e_circumflex:
				case irs::e_diaeresis:
				case irs::i:
				case irs::i_circumflex:
				case irs::o:
				case irs::o_circumflex:
				case irs::o_diaeresis:
				case irs::u:
				case irs::u_circumflex:
				case irs::u_diaeresis:
					return true;
				default:
					return false;
				}
			}

			inline auto is_idiphtong(irs::type ph) -> bool
			{
				switch (ph)
				{
				case irs::a:
				case irs::e:
				case irs::e_diaeresis:
				case irs::o:
				case irs::o_diaeresis:
				case irs::u:
					return true;
				default:
					return false;
				}
			}

			inline auto is_udiphtong(irs::type ph) -> bool
			{
				switch (ph)
				{
				case irs::a:
				case irs::e:
				case irs::e_diaeresis:
				case irs::i:
				case irs::o:
				case irs::o_diaeresis:
					return true;
				default:
					return false;
				}
			}

			inline auto is_consonant_orth(wchar_t c) -> bool
			{
				switch (c)
				{
				case L'b':
				case L'B':
				case L'c':
				case L'C':
				case L'č':
				case L'Č':
				case L'ç':
				case L'Ç':
				case L'd':
				case L'D':
				case L'f':
				case L'F':
				case L'g':
				case L'G':
				case L'h':
				case L'H':
				case L'j':
				case L'J':
				case L'k':
				case L'K':
				case L'l':
				case L'L':
				case L'ļ':
				case L'Ļ':
				case L'm':
				case L'M':
				case L'n':
				case L'N':
				case L'ň':
				case L'Ň':
				case L'p':
				case L'P':
				case L'q':
				case L'Q':
				case L'r':
				case L'R':
				case L'ř':
				case L'Ř':
				case L's':
				case L'S':
				case L'š':
				case L'Š':
				case L't':
				case L'T':
				case L'ţ':
				case L'Ţ':
				case L'v':
				case L'V':
				case L'w':
				case L'W':
				case L'x':
				case L'X':
				case L'y':
				case L'Y':
				case L'z':
				case L'Z':
				case L'ż':
				case L'Ż':
				case L'ž':
				case L'Ž':
				case L'’':
				case L'\'':
				case L'`':
				case L'-':
					return true;
				default:
					return false;
				}
			}

			enum class tone_t : unsigned char
			{
				falling,
				low,
				high,
				rising,
				falling_rising,
				rising_falling
			};

			template<typename Iterator>
			auto to_irs(Iterator begin, Iterator end) -> std::tuple<std::vector<irs::type>, std::vector<unsigned int>, std::vector<unsigned int>, unsigned, unsigned, tone_t>
			{
				std::vector<irs::type> phs;
				std::vector<unsigned int> unstressed;
				std::vector<unsigned int> diacriticized;
				unsigned stressed = 0;
				unsigned syllable = 1;
				tone_t tone = tone_t::falling;

				auto ins = [&phs](irs::type p)
				{
					phs.push_back(p);
				};
				auto inssylb = [&syllable, &unstressed]()
				{
					unstressed.push_back(syllable);
				};
				auto stress_doubling = [&syllable, &stressed, &phs, &diacriticized](irs::type p) -> irs::type
				{
					if (!phs.empty() && phs.back() == p)
					{
						if (stressed != 0)
						{
							throw std::invalid_argument("Invalid stress indication");
						}
						stressed = syllable - 1;
						return irs::none;
					}
					else
					{
						diacriticized.push_back(syllable++);
						return static_cast<irs::type>(p);
					}
				};
				auto check_syllabic_consonant = [&syllable, &begin, &end, &phs]()
				{
					if (phs.empty() && (begin + 1 != end) && is_consonant_orth(begin[1]))
					{
						syllable++;
					}
				};
				auto set_tone = [&tone, &phs](tone_t t)
				{
					if (phs.empty())
					{
						tone = t;
					}
					else
					{
						throw std::invalid_argument("Invalid tone mark");
					}
				};

				for (; begin != end; ++begin)
				{
					irs::type p = irs::none;
					switch (*begin)
					{
					case L'_':
						set_tone(tone_t::low);
						break;
					case L'¯':
					case L'‾':
					case L'⁻':
						set_tone(tone_t::high);
						break;
					case L'/':
					case L'⸍':
						set_tone(tone_t::rising);
						break;
					case L'ˇ':
					case L'˘':
					case L'~':
					case L'˜':
						set_tone(tone_t::falling_rising);
						break;
					case L'^':
						set_tone(tone_t::rising_falling);
						break;
					case L'b':
					case L'B':
						p = irs::b;
						break;
					case L'c':
					case L'C':
						p = irs::c;
						break;
					case L'č':
					case L'Č':
						p = irs::c_caron;
						break;
					case L'ç':
					case L'Ç':
						p = irs::c_cedilla;
						break;
					case L'd':
					case L'D':
						p = irs::d;
						break;
					case L'f':
					case L'F':
						p = irs::f;
						break;
					case L'g':
					case L'G':
						p = irs::g;
						break;
					case L'h':
					case L'H':
						if (phs.empty())
						{
							p = irs::h;
						}
						else
						{
							irs::type& prev = phs.back();
							switch (prev)
							{
							case irs::d:
								prev = irs::dh;
								if ((phs.size() > 1) && (phs[phs.size() - 2] == irs::d))
								{
									phs[phs.size() - 2] = irs::dh;
								}
								break;
							case irs::x:
								prev = irs::xh;
								if ((phs.size() > 1) && (phs[phs.size() - 2] == irs::x))
								{
									phs[phs.size() - 2] = irs::xh;
								}
								break;
							default:
								p = irs::h;
							}
						}
						break;
					case L'j':
					case L'J':
						p = irs::j;
						break;
					case L'k':
					case L'K':
						p = irs::k;
						break;
					case L'l':
					case L'L':
						p = irs::l;
						check_syllabic_consonant();
						break;
					case L'ļ':
					case L'Ļ':
						p = irs::l_cedilla;
						break;
					case L'm':
					case L'M':
						p = irs::m;
						check_syllabic_consonant();
						break;
					case L'n':
					case L'N':
						p = irs::n;
						check_syllabic_consonant();
						break;
					case L'ň':
					case L'Ň':
						p = irs::n_caron;
						check_syllabic_consonant();
						break;
					case L'p':
					case L'P':
						p = irs::p;
						break;
					case L'q':
					case L'Q':
						p = irs::q;
						break;
					case L'r':
					case L'R':
						p = irs::r;
						check_syllabic_consonant();
						break;
					case L'ř':
					case L'Ř':
						p = irs::r_caron;
						break;
					case L's':
					case L'S':
						p = irs::s;
						break;
					case L'š':
					case L'Š':
						p = irs::s_caron;
						break;
					case L't':
					case L'T':
						p = irs::t;
						break;
					case L'ţ':
					case L'Ţ':
						p = irs::t_cedilla;
						break;
					case L'v':
					case L'V':
						p = irs::v;
						break;
					case L'w':
					case L'W':
						p = irs::w;
						break;
					case L'x':
					case L'X':
						p = irs::x;
						break;
					case L'y':
					case L'Y':
						p = irs::y;
						break;
					case L'z':
					case L'Z':
						p = irs::z;
						break;
					case L'ż':
					case L'Ż':
						p = irs::z_overdot;
						break;
					case L'ž':
					case L'Ž':
						p = irs::z_caron;
						break;
					case L'’':
					case L'\'':
					case L'`':
						if (phs.empty())
						{
							p = irs::glottal_stop;
							break;
						}
						else
						{
							irs::type& prev = phs.back();
							irs::type prev_original = prev;
							bool ejective = true;
							switch (prev)
							{
							case irs::c:
								prev = irs::c_eject;
								break;
							case irs::c_caron:
								prev = irs::c_caron_eject;
								break;
							case irs::k:
								prev = irs::k_eject;
								break;
							case irs::p:
								prev = irs::p_eject;
								break;
							case irs::q:
								prev = irs::q_eject;
								break;
							case irs::t:
								prev = irs::t_eject;
								break;
							default:
								ejective = false;
								p = irs::glottal_stop;
							}
							if (ejective && (phs.size() > 1) && (phs[phs.size() - 2] == prev_original))
							{
								phs[phs.size() - 2] = prev;
							}
						}
						break;
					case L'a':
					case L'A':
						p = irs::a;
						syllable++;
						break;
					case L'â':
					case L'Â':
						p = stress_doubling(irs::a_circumflex);
						break;
					case L'e':
					case L'E':
						p = irs::e;
						syllable++;
						break;
					case L'ê':
					case L'Ê':
						p = stress_doubling(irs::e_circumflex);
						break;
					case L'ë':
					case L'Ë':
						p = stress_doubling(irs::e_diaeresis);
						break;
					case L'i':
					case L'I':
						p = irs::i;
						if (phs.empty() || !is_idiphtong(phs.back()))
						{
							syllable++;
						}
						break;
					case L'î':
					case L'Î':
						if (phs.empty())
						{
							p = irs::i_circumflex;
							syllable++;
						}
						else if (is_idiphtong(phs.back()))
						{
							ins(irs::syllable_boundary_vc);
							inssylb();
							p = irs::i;
							syllable++;
						}
						else
						{
							p = stress_doubling(irs::i_circumflex);
						}
						break;
					case L'o':
					case L'O':
						p = irs::o;
						syllable++;
						break;
					case L'ô':
					case L'Ô':
						p = stress_doubling(irs::o_circumflex);
						break;
					case L'ö':
					case L'Ö':
						p = stress_doubling(irs::o_diaeresis);
						break;
					case L'u':
					case L'U':
						p = irs::u;
						if (phs.empty() || !is_udiphtong(phs.back()))
						{
							syllable++;
						}
						break;
					case L'û':
					case L'Û':
						if (phs.empty())
						{
							p = irs::u_circumflex;
							syllable++;
						}
						else if (is_udiphtong(phs.back()))
						{
							ins(irs::syllable_boundary_vc);
							inssylb();
							p = irs::u;
							syllable++;
						}
						else
						{
							p = stress_doubling(irs::u_circumflex);
						}
						break;
					case L'ü':
					case L'Ü':
						p = stress_doubling(irs::u_diaeresis);
						break;
					case L'ʰ':
						if (phs.empty())
						{
							throw std::invalid_argument("Invalid aspiration encountered");
						}
						else
						{
							irs::type& prev = phs.back();
							irs::type prev_original = prev;
							switch (prev)
							{
							case irs::c:
								prev = irs::c_h;
								break;
							case irs::c_caron:
								prev = irs::c_caron_h;
								break;
							case irs::k:
								prev = irs::k_h;
								break;
							case irs::p:
								prev = irs::p_h;
								break;
							case irs::q:
								prev = irs::q_h;
								break;
							case irs::t:
								prev = irs::t_h;
								break;
							default:
								throw std::invalid_argument("Invalid aspiration encountered");
							}
							//std::wcout << i222++ << L"\t" << phs.size() << L"\t" << (unsigned int)( phs.size() > 1 ? phs[phs.size() - 2] : phs[phs.size() - 1] ) << L"\t" << (unsigned int) prev_original << std::endl;
							if ((phs.size() > 1) && (phs[phs.size() - 2] == prev_original))
							{
								phs[phs.size() - 2] = prev;
							}
						}
						break;
					case L'-':
						p = irs::syllable_boundary;
						syllable++;
						break;
					case L'ù':
					case L'Ù':
						if (!phs.empty() && is_udiphtong(phs.back()))
						{
							ins(irs::syllable_boundary);
						}
						p = irs::u;
						inssylb();
						syllable++;
						break;
					case L'ì':
					case L'Ì':
						if (!phs.empty() && is_idiphtong(phs.back()))
						{
							ins(irs::syllable_boundary);
						}
						p = irs::i;
						inssylb();
						syllable++;
						break;
					case L'à':
					case L'À':
						inssylb();
						syllable++;
						p = irs::a;
						break;
					case L'è':
					case L'È':
						inssylb();
						syllable++;
						p = irs::e;
						break;
					case L'ò':
					case L'Ò':
						inssylb();
						syllable++;
						p = irs::o;
						break;
					case L'ú':
					case L'Ú':
						if (!phs.empty() && is_udiphtong(phs.back()))
						{
							ins(irs::syllable_boundary);
						}
						p = irs::u;
						if (stressed != 0)
						{
							throw std::invalid_argument("Invalid stress indication");
						}
						stressed = syllable++;
						break;
					case L'í':
					case L'Í':
						if (!phs.empty() && is_idiphtong(phs.back()))
						{
							ins(irs::syllable_boundary);
						}
						p = irs::i;
						if (stressed != 0)
						{
							throw std::invalid_argument("Invalid stress indication");
						}
						stressed = syllable++;
						break;
					case L'á':
					case L'Á':
						if (stressed != 0)
						{
							throw std::invalid_argument("Invalid stress indication");
						}
						stressed = syllable++;
						p = irs::a;
						break;
					case L'é':
					case L'É':
						if (stressed != 0)
						{
							throw std::invalid_argument("Invalid stress indication");
						}
						stressed = syllable++;
						p = irs::e;
						break;
					case L'ó':
					case L'Ó':
						if (stressed != 0)
						{
							throw std::invalid_argument("Invalid stress indication");
						}
						stressed = syllable++;
						p = irs::o;
						break;
					default:
						p = irs::none;
					}
					if (p != irs::none)
					{
						ins(p);
					}
				}
				return { phs, unstressed, diacriticized, stressed, syllable, tone };
			}

			template<typename Container>
			auto to_irs(Container container)
			{
				return to_irs(std::begin(container), std::end(container));
			}

			template<>
			auto to_irs<const wchar_t*>(const wchar_t* strlit)
			{
				auto view = std::wstring_view(strlit);
				return to_irs(view.begin(), view.end());
			}

			template<typename Iterator>
			auto to_irs2(Iterator begin, Iterator end)
			{
				auto [phs, unstressed, diacriticized, stressed, syllable, tone] = to_irs(begin, end);
				return phs;
			}

			template<typename Container>
			auto to_irs2(Container container)
			{
				return to_irs2(std::begin(container), std::end(container));
			}

			template<>
			auto to_irs2<const wchar_t*>(const wchar_t* strlit)
			{
				auto view = std::wstring_view(strlit);
				return to_irs2(view.begin(), view.end());
			}

			enum class stress
			{
				penultimate,
				ultimate,
				antepenultimate,
				preantepenultimate
			};

			struct ir_word
			{
				std::vector<irs::type> _phonemes;
				stress _stress;
				tone_t _tone;
			};

		}
	}
}
