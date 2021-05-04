// refactored code

#include <tuple>
#include <boost/bimap.hpp>
#include <boost/bimap/unordered_set_of.hpp>
#include <boost/assign.hpp>
#include "../nstring.h"
#include "morphology.h"

namespace ithkuil
{
	namespace v3
	{
		template<typename T>
		using abbreviation_map_for = boost::bimap<boost::bimaps::unordered_set_of<nstring_view>, boost::bimaps::unordered_set_of<T>>;

		template<typename... Ts>
		using abbreviations_base = std::tuple<abbreviation_map_for<Ts>...>;

		using abbreviations_map_t = abbreviations_base <
			pattern_t,
			stem_t,
			designation_t,
			designated_stem_t,
			function_t,
			configuration_t,
			affiliation_t,
			perspective_t,
			extension_t,
			essence_t,
			context_t,
			version_t,
			format_t,
			ccase_t,
			relation_t,
			illocution_t,
			mood_t,
			phase_t,
			sanction_t,
			valence_t,
			validation_t,
			aspect_t,
			modality_t,
			level_t,
			bias_t/*
			referent_t,
			suffix_type_t,
			suffix_degree_t,
			suffix_t*/
		>;

		template<typename T>
		constexpr auto& get(abbreviations_map_t& abbr) noexcept
		{
			return std::get<abbreviation_map_for<T>>(abbr);
		}

		template<typename T>
		constexpr auto&& get(abbreviations_map_t&& abbr) noexcept
		{
			return std::get<abbreviation_map_for<T>>(abbr);
		}

		template<typename T>
		constexpr const auto& get(const abbreviations_map_t& abbr) noexcept
		{
			return std::get<abbreviation_map_for<T>>(abbr);
		}

		template<typename T>
		constexpr const auto&& get(const abbreviations_map_t&& abbr) noexcept
		{
			return std::get<abbreviation_map_for<T>>(abbr);
		}

#pragma warning(disable : 4834)

		inline abbreviations_map_t abbreviation
		{
			boost::assign::list_of<abbreviation_map_for<pattern_t>::relation>
				(NSTR("1"), pattern_t::p1)
				(NSTR("2"), pattern_t::p2)
				(NSTR("3"), pattern_t::p3),
			boost::assign::list_of<abbreviation_map_for<stem_t>::relation>
				(NSTR("1"), stem_t::s1)
				(NSTR("2"), stem_t::s2)
				(NSTR("3"), stem_t::s3),
			boost::assign::list_of<abbreviation_map_for<designation_t>::relation>
				(NSTR("IFL"), designation_t::informal)
				(NSTR("FML"), designation_t::formal),
			boost::assign::list_of<abbreviation_map_for<designated_stem_t>::relation>
				(NSTR("IFL/1/1"), designated_stem_t::iflp1s1)
				(NSTR("IFL/1/2"), designated_stem_t::iflp1s2)
				(NSTR("IFL/1/3"), designated_stem_t::iflp1s3)
				(NSTR("IFL/2/1"), designated_stem_t::iflp2s1)
				(NSTR("IFL/2/2"), designated_stem_t::iflp2s2)
				(NSTR("IFL/2/3"), designated_stem_t::iflp2s3)
				(NSTR("IFL/3/1"), designated_stem_t::iflp3s1)
				(NSTR("IFL/3/2"), designated_stem_t::iflp3s2)
				(NSTR("IFL/3/3"), designated_stem_t::iflp3s3)
				(NSTR("FML/1/1"), designated_stem_t::fmlp1s1)
				(NSTR("FML/1/2"), designated_stem_t::fmlp1s2)
				(NSTR("FML/1/3"), designated_stem_t::fmlp1s3)
				(NSTR("FML/2/1"), designated_stem_t::fmlp2s1)
				(NSTR("FML/2/3"), designated_stem_t::fmlp2s2)
				(NSTR("FML/2/3"), designated_stem_t::fmlp2s3)
				(NSTR("FML/3/1"), designated_stem_t::fmlp3s1)
				(NSTR("FML/3/2"), designated_stem_t::fmlp3s2),
			boost::assign::list_of<abbreviation_map_for<function_t>::relation>
				(NSTR("STA"), v3::function_t::stative)
				(NSTR("DYN"), v3::function_t::dynamic)
				(NSTR("MNF"), v3::function_t::manifestive)
				(NSTR("DSC"), v3::function_t::descriptive),
			boost::assign::list_of<abbreviation_map_for<configuration_t>::relation>
				(NSTR("UNI"), v3::configuration_t::uniplex)
				(NSTR("DPX"), v3::configuration_t::duplex)
				(NSTR("DCT"), v3::configuration_t::discrete)
				(NSTR("AGG"), v3::configuration_t::aggregative)
				(NSTR("SEG"), v3::configuration_t::segmentative)
				(NSTR("CPN"), v3::configuration_t::componential)
				(NSTR("COH"), v3::configuration_t::coherent)
				(NSTR("CST"), v3::configuration_t::composite)
				(NSTR("MLT"), v3::configuration_t::multiform),
			boost::assign::list_of<abbreviation_map_for<affiliation_t>::relation>
				(NSTR("ASO"), v3::affiliation_t::associative)
				(NSTR("VAR"), v3::affiliation_t::variative)
				(NSTR("COA"), v3::affiliation_t::coalescent)
				(NSTR("CSL"), v3::affiliation_t::consolidative),
			boost::assign::list_of<abbreviation_map_for<perspective_t>::relation>
				(NSTR("M"), v3::perspective_t::monadic)
				(NSTR("A"), v3::perspective_t::abstract)
				(NSTR("N"), v3::perspective_t::nomic)
				(NSTR("U"), v3::perspective_t::unbounded),
			boost::assign::list_of<abbreviation_map_for<extension_t>::relation>
				(NSTR("DEL"), v3::extension_t::delimitive)
				(NSTR("DPL"), v3::extension_t::depletive)
				(NSTR("GRA"), v3::extension_t::graduative)
				(NSTR("ICP"), v3::extension_t::inceptive)
				(NSTR("PRX"), v3::extension_t::proximal)
				(NSTR("TRM"), v3::extension_t::terminative),
			boost::assign::list_of<abbreviation_map_for<essence_t>::relation>
				(NSTR("NRM"), v3::essence_t::normal)
				(NSTR("RPV"), v3::essence_t::representative),
			boost::assign::list_of<abbreviation_map_for<context_t>::relation>
				(NSTR("EXS"), v3::context_t::existential)
				(NSTR("FNC"), v3::context_t::functional)
				(NSTR("RPS"), v3::context_t::representational)
				(NSTR("AMG"), v3::context_t::amalgamate),
			boost::assign::list_of<abbreviation_map_for<version_t>::relation>
				(NSTR("PRC"), v3::version_t::processual)
				(NSTR("CPT"), v3::version_t::completive)
				(NSTR("INE"), v3::version_t::ineffectual)
				(NSTR("INC"), v3::version_t::incompletive)
				(NSTR("PST"), v3::version_t::positive)
				(NSTR("EFC"), v3::version_t::effective),
			boost::assign::list_of<abbreviation_map_for<format_t>::relation>
				(NSTR("F_0"), v3::format_t::none)
				(NSTR("SCH"), v3::format_t::schematic)
				(NSTR("ISR"), v3::format_t::instrumentative)
				(NSTR("ATH"), v3::format_t::authoritive)
				(NSTR("RSL"), v3::format_t::resultative)
				(NSTR("SBQ"), v3::format_t::subsequent)
				(NSTR("CCM"), v3::format_t::concommitant)
				(NSTR("OBJ"), v3::format_t::objective)
				(NSTR("PRT"), v3::format_t::precurrent)
				(NSTR("AFI"), v3::format_t::affinitive),
			boost::assign::list_of<abbreviation_map_for<ccase_t>::relation>
				(NSTR("OBL"), v3::ccase_t::oblique)
				(NSTR("IND"), v3::ccase_t::inducive)
				(NSTR("ABS"), v3::ccase_t::absolutive)
				(NSTR("ERG"), v3::ccase_t::ergative)
				(NSTR("EFF"), v3::ccase_t::effectuative)
				(NSTR("AFF"), v3::ccase_t::affective)
				(NSTR("DAT"), v3::ccase_t::dative)
				(NSTR("INS"), v3::ccase_t::instrumental)
				(NSTR("ACT"), v3::ccase_t::activative)
				(NSTR("DER"), v3::ccase_t::derivative)
				(NSTR("SIT"), v3::ccase_t::situative)
				(NSTR("POS"), v3::ccase_t::possessive)
				(NSTR("PRP"), v3::ccase_t::proprietive)
				(NSTR("GEN"), v3::ccase_t::genitive)
				(NSTR("ATT"), v3::ccase_t::attributive)
				(NSTR("PDC"), v3::ccase_t::productive)
				(NSTR("ITP"), v3::ccase_t::interpretative)
				(NSTR("OGN"), v3::ccase_t::originative)
				(NSTR("PAR"), v3::ccase_t::partitive)
				(NSTR("CRS"), v3::ccase_t::contrastive)
				(NSTR("CPS"), v3::ccase_t::compositive)
				(NSTR("PRD"), v3::ccase_t::predicative)
				(NSTR("MED"), v3::ccase_t::mediative)
				(NSTR("APL"), v3::ccase_t::applicative)
				(NSTR("PUR"), v3::ccase_t::purposive)
				(NSTR("CSD"), v3::ccase_t::considerative)
				(NSTR("ESS"), v3::ccase_t::essive)
				(NSTR("ASI"), v3::ccase_t::assimilative)
				(NSTR("FUN"), v3::ccase_t::functive)
				(NSTR("TFM"), v3::ccase_t::transformative)
				(NSTR("REF"), v3::ccase_t::referential)
				(NSTR("CLA"), v3::ccase_t::classificative)
				(NSTR("CNV"), v3::ccase_t::conductive)
				(NSTR("IDP"), v3::ccase_t::interdependent)
				(NSTR("BEN"), v3::ccase_t::benefactive)
				(NSTR("TSP"), v3::ccase_t::transpositive)
				(NSTR("CMM"), v3::ccase_t::commutative)
				(NSTR("COM"), v3::ccase_t::comitative)
				(NSTR("CNJ"), v3::ccase_t::conjunctive)
				(NSTR("UTL"), v3::ccase_t::utilitative)
				(NSTR("ABE"), v3::ccase_t::abessive)
				(NSTR("CVS"), v3::ccase_t::conversive)
				(NSTR("COR"), v3::ccase_t::correlative)
				(NSTR("DEP"), v3::ccase_t::dependent)
				(NSTR("PVS"), v3::ccase_t::provisional)
				(NSTR("PTL"), v3::ccase_t::postulative)
				(NSTR("CON"), v3::ccase_t::concessive)
				(NSTR("EXC"), v3::ccase_t::exceptive)
				(NSTR("AVR"), v3::ccase_t::aversive)
				(NSTR("CMP"), v3::ccase_t::comparative)
				(NSTR("SML"), v3::ccase_t::simultaneitive)
				(NSTR("ASS"), v3::ccase_t::assessive)
				(NSTR("CNR"), v3::ccase_t::concursive)
				(NSTR("ACS"), v3::ccase_t::acessive)
				(NSTR("DFF"), v3::ccase_t::diffusive)
				(NSTR("PER"), v3::ccase_t::periodic)
				(NSTR("PRO"), v3::ccase_t::prolapsive)
				(NSTR("PCV"), v3::ccase_t::precursive)
				(NSTR("PCR"), v3::ccase_t::postcursive)
				(NSTR("ELP"), v3::ccase_t::elapsive)
				(NSTR("ALP"), v3::ccase_t::allapsive)
				(NSTR("INP"), v3::ccase_t::interpolative)
				(NSTR("EPS"), v3::ccase_t::episodic)
				(NSTR("PLM"), v3::ccase_t::prolimitive)
				(NSTR("LIM"), v3::ccase_t::limitative)
				(NSTR("LOC"), v3::ccase_t::locative)
				(NSTR("ORI"), v3::ccase_t::orientative)
				(NSTR("PSV"), v3::ccase_t::procursive)
				(NSTR("ALL"), v3::ccase_t::allative)
				(NSTR("ABL"), v3::ccase_t::ablative)
				(NSTR("NAV"), v3::ccase_t::navigative)
				(NSTR("VOC"), v3::ccase_t::vocative)
				(NSTR("CMP1A"), v3::ccase_t::comparative1a)
				(NSTR("CMP2A"), v3::ccase_t::comparative2a)
				(NSTR("CMP3A"), v3::ccase_t::comparative3a)
				(NSTR("CMP4A"), v3::ccase_t::comparative4a)
				(NSTR("CMP5A"), v3::ccase_t::comparative5a)
				(NSTR("CMP6A"), v3::ccase_t::comparative6a)
				(NSTR("CMP7A"), v3::ccase_t::comparative7a)
				(NSTR("CMP8A"), v3::ccase_t::comparative8a)
				(NSTR("CMP1B"), v3::ccase_t::comparative1b)
				(NSTR("CMP2B"), v3::ccase_t::comparative2b)
				(NSTR("CMP3B"), v3::ccase_t::comparative3b)
				(NSTR("CMP4B"), v3::ccase_t::comparative4b)
				(NSTR("CMP5B"), v3::ccase_t::comparative5b)
				(NSTR("CMP6B"), v3::ccase_t::comparative6b)
				(NSTR("CMP7B"), v3::ccase_t::comparative7b)
				(NSTR("CMP8B"), v3::ccase_t::comparative8b)
				(NSTR("CMP1C"), v3::ccase_t::comparative1c)
				(NSTR("CMP2C"), v3::ccase_t::comparative2c)
				(NSTR("CMP3C"), v3::ccase_t::comparative3c)
				(NSTR("CMP4C"), v3::ccase_t::comparative4c)
				(NSTR("CMP5C"), v3::ccase_t::comparative5c)
				(NSTR("CMP6C"), v3::ccase_t::comparative6c)
				(NSTR("CMP7C"), v3::ccase_t::comparative7c)
				(NSTR("CMP8C"), v3::ccase_t::comparative8c),
			boost::assign::list_of<abbreviation_map_for<relation_t>::relation>
				(NSTR("UNFRAMED"), v3::relation_t::unframed)
				(NSTR("FRAMED"), v3::relation_t::framed),
			boost::assign::list_of<abbreviation_map_for<illocution_t>::relation>
				(NSTR("ASR"), illocution_t::assertive)
				(NSTR("IRG"), illocution_t::interrogative)
				(NSTR("DIR"), illocution_t::directive)
				(NSTR("ADM"), illocution_t::admonitive)
				(NSTR("HOR"), illocution_t::hortative)
				(NSTR("DEC"), illocution_t::declarative),
			boost::assign::list_of<abbreviation_map_for<mood_t>::relation>
				(NSTR("FAC"), v3::mood_t::factual)
				(NSTR("SUB"), v3::mood_t::subjunctive)
				(NSTR("ASM"), v3::mood_t::assumptive)
				(NSTR("SPC"), v3::mood_t::speculative)
				(NSTR("COU"), v3::mood_t::counterfactive)
				(NSTR("HYP"), v3::mood_t::hypothetical)
				(NSTR("IPL"), v3::mood_t::implicative)
				(NSTR("ASC"), v3::mood_t::ascriptive),
			boost::assign::list_of<abbreviation_map_for<phase_t>::relation>
				(NSTR("CTX"), phase_t::contextual)
				(NSTR("PCT"), phase_t::punctual)
				(NSTR("ITR"), phase_t::iterative)
				(NSTR("REP"), phase_t::repetitive)
				(NSTR("ITM"), phase_t::intermittent)
				(NSTR("RCT"), phase_t::recurrent)
				(NSTR("FRE"), phase_t::frequentative)
				(NSTR("FRG"), phase_t::fragmentative)
				(NSTR("FLC"), phase_t::fluctuative),
			boost::assign::list_of<abbreviation_map_for<sanction_t>::relation>
				(NSTR("PPS"), sanction_t::propositional)
				(NSTR("EPI"), sanction_t::epistemic)
				(NSTR("ALG"), sanction_t::allegative)
				(NSTR("IPU"), sanction_t::imputative)
				(NSTR("RFU"), sanction_t::refutative)
				(NSTR("REB"), sanction_t::rebuttative)
				(NSTR("THR"), sanction_t::theoretical)
				(NSTR("EXV"), sanction_t::expatiative)
				(NSTR("AXM"), sanction_t::axiomatic),
			boost::assign::list_of<abbreviation_map_for<valence_t>::relation>
				(NSTR("MNO"), v3::valence_t::monoactive)
				(NSTR("PRL"), v3::valence_t::parallel)
				(NSTR("CRO"), v3::valence_t::corollary)
				(NSTR("RCP"), v3::valence_t::reciprocal)
				(NSTR("CPL"), v3::valence_t::complementary)
				(NSTR("NNR"), v3::valence_t::nonrelational)
				(NSTR("DUP"), v3::valence_t::duplicative)
				(NSTR("DEM"), v3::valence_t::demonstrative)
				(NSTR("RES"), v3::valence_t::resistive)
				(NSTR("IMT"), v3::valence_t::imitative)
				(NSTR("CNG"), v3::valence_t::contingent)
				(NSTR("PTI"), v3::valence_t::participative)
				(NSTR("IDC"), v3::valence_t::indicative)
				(NSTR("MUT"), v3::valence_t::mutual),
			boost::assign::list_of<abbreviation_map_for<validation_t>::relation>
				(NSTR("CNF"), v3::validation_t::confirmative)
				(NSTR("AFM"), v3::validation_t::affirmative)
				(NSTR("RPT"), v3::validation_t::reportive)
				(NSTR("INF"), v3::validation_t::inferential)
				(NSTR("ITU"), v3::validation_t::intuitive)
				(NSTR("PSM"), v3::validation_t::presumptive)
				(NSTR("PSM2"), v3::validation_t::presumptive2)
				(NSTR("PPT"), v3::validation_t::purportive)
				(NSTR("PPT2"), v3::validation_t::purportive2)
				(NSTR("CJT"), v3::validation_t::conjectural)
				(NSTR("DUB"), v3::validation_t::dubitative)
				(NSTR("TEN"), v3::validation_t::tentative)
				(NSTR("PUT"), v3::validation_t::putative)
				(NSTR("IPB"), v3::validation_t::improbable),
			boost::assign::list_of<abbreviation_map_for<aspect_t>::relation>
				(NSTR("A_0"), v3::aspect_t::none)
				(NSTR("RTR"), v3::aspect_t::retrospective)
				(NSTR("PRS"), v3::aspect_t::prospective)
				(NSTR("HAB"), v3::aspect_t::habitual)
				(NSTR("PRG"), v3::aspect_t::progressive)
				(NSTR("IMM"), v3::aspect_t::imminent)
				(NSTR("PCS"), v3::aspect_t::precessive)
				(NSTR("REG"), v3::aspect_t::regulative)
				(NSTR("EXP"), v3::aspect_t::experiential)
				(NSTR("RSM"), v3::aspect_t::resumptive)
				(NSTR("CSS"), v3::aspect_t::cessative)
				(NSTR("RCS"), v3::aspect_t::recessative)
				(NSTR("PAU"), v3::aspect_t::pausal)
				(NSTR("RGR"), v3::aspect_t::regressive)
				(NSTR("PCL"), v3::aspect_t::preclusive)
				(NSTR("CNT"), v3::aspect_t::continuative)
				(NSTR("ICS"), v3::aspect_t::incessative)
				(NSTR("PMP"), v3::aspect_t::preemptive)
				(NSTR("CLM"), v3::aspect_t::climactic)
				(NSTR("PTC"), v3::aspect_t::protractive)
				(NSTR("TMP"), v3::aspect_t::temporary)
				(NSTR("MTV"), v3::aspect_t::motive)
				(NSTR("CSQ"), v3::aspect_t::consequential)
				(NSTR("SQN"), v3::aspect_t::sequential)
				(NSTR("EPD"), v3::aspect_t::expeditive)
				(NSTR("DCL"), v3::aspect_t::disclusive)
				(NSTR("CCL"), v3::aspect_t::conclusive)
				(NSTR("CUL"), v3::aspect_t::culminative)
				(NSTR("IMD"), v3::aspect_t::intermediative)
				(NSTR("TRD"), v3::aspect_t::tardative)
				(NSTR("TNS"), v3::aspect_t::transitional)
				(NSTR("ITC"), v3::aspect_t::intercommutative)
				(NSTR("CSM"), v3::aspect_t::consumptive),
			boost::assign::list_of<abbreviation_map_for<modality_t>::relation>
				(NSTR("M_0"), v3::modality_t::none)
				(NSTR("DES"), v3::modality_t::desiderative)
				(NSTR("ASP"), v3::modality_t::aspirative)
				(NSTR("EPC"), v3::modality_t::expectative)
				(NSTR("CRD"), v3::modality_t::credential)
				(NSTR("REQ"), v3::modality_t::requisitive)
				(NSTR("EXH"), v3::modality_t::exhortative)
				(NSTR("OPR"), v3::modality_t::opportunitive)
				(NSTR("CPC"), v3::modality_t::capacitative)
				(NSTR("PRM"), v3::modality_t::permissive)
				(NSTR("PTN"), v3::modality_t::potential)
				(NSTR("CLS"), v3::modality_t::compulsory)
				(NSTR("OBG"), v3::modality_t::obligative)
				(NSTR("IMS"), v3::modality_t::impositive)
				(NSTR("ADV"), v3::modality_t::advocative)
				(NSTR("ITV"), v3::modality_t::intentive)
				(NSTR("ANT"), v3::modality_t::anticipative)
				(NSTR("DSP"), v3::modality_t::dispositive)
				(NSTR("PRE"), v3::modality_t::preparative)
				(NSTR("NEC"), v3::modality_t::necessitative)
				(NSTR("DCV"), v3::modality_t::decisive)
				(NSTR("PTV"), v3::modality_t::proclivitive)
				(NSTR("VOL"), v3::modality_t::voluntative)
				(NSTR("ACC"), v3::modality_t::accordative)
				(NSTR("ICL"), v3::modality_t::inclinative)
				(NSTR("CML"), v3::modality_t::compulsive)
				(NSTR("DVR"), v3::modality_t::divertive)
				(NSTR("DVT"), v3::modality_t::devotive)
				(NSTR("PFT"), v3::modality_t::preferential)
				(NSTR("IPS"), v3::modality_t::impressional)
				(NSTR("PMS"), v3::modality_t::promissory),
			boost::assign::list_of<abbreviation_map_for<level_t>::relation>
				(NSTR("LVL_000"), v3::level_t::none)
				(NSTR("EQU_REL"), v3::level_t::equative_relative)
				(NSTR("SUR_REL"), v3::level_t::surpassive_relative)
				(NSTR("DFC_REL"), v3::level_t::deficient_relative)
				(NSTR("OPT_REL"), v3::level_t::optimal_relative)
				(NSTR("MIN_REL"), v3::level_t::minimal_relative)
				(NSTR("SPL_REL"), v3::level_t::superlative_relative)
				(NSTR("IFR_REL"), v3::level_t::inferior_relative)
				(NSTR("SPQ_REL"), v3::level_t::superequative_relative)
				(NSTR("SBE_REL"), v3::level_t::subequative_relative)
				(NSTR("EQU_ABS"), v3::level_t::equative_absolute)
				(NSTR("SUR_ABS"), v3::level_t::surpassive_absolute)
				(NSTR("DFC_ABS"), v3::level_t::deficient_absolute)
				(NSTR("OPT_ABS"), v3::level_t::optimal_absolute)
				(NSTR("MIN_ABS"), v3::level_t::minimal_absolute)
				(NSTR("SPL_ABS"), v3::level_t::superlative_absolute)
				(NSTR("IFR_ABS"), v3::level_t::inferior_absolute)
				(NSTR("SPQ_ABS"), v3::level_t::superequative_absolute)
				(NSTR("SBE_ABS"), v3::level_t::subequative_absolute),
			boost::assign::list_of<abbreviation_map_for<bias_t>::relation>
				(NSTR("ASU"), v3::bias_t::assurative)
				(NSTR("HPB"), v3::bias_t::hyperbolic)
				(NSTR("COI"), v3::bias_t::coincidental)
				(NSTR("ACP"), v3::bias_t::acceptive)
				(NSTR("RAC"), v3::bias_t::reactive)
				(NSTR("STU"), v3::bias_t::stupefactive)
				(NSTR("CTV"), v3::bias_t::contemplative)
				(NSTR("DPV"), v3::bias_t::desperative)
				(NSTR("RVL"), v3::bias_t::revelative)
				(NSTR("GRT"), v3::bias_t::gratificative)
				(NSTR("SOL"), v3::bias_t::solicitive)
				(NSTR("SEL"), v3::bias_t::selective)
				(NSTR("IRO"), v3::bias_t::ironic)
				(NSTR("EXA"), v3::bias_t::exasperative)
				(NSTR("LTL"), v3::bias_t::literal)
				(NSTR("CRR"), v3::bias_t::corrective)
				(NSTR("EUP"), v3::bias_t::euphemistic)
				(NSTR("SKP"), v3::bias_t::skeptical)
				(NSTR("CYN"), v3::bias_t::cynical)
				(NSTR("CTP"), v3::bias_t::contemptive)
				(NSTR("DSM"), v3::bias_t::dismissive)
				(NSTR("IDG"), v3::bias_t::indignative)
				(NSTR("SGS"), v3::bias_t::suggestive)
				(NSTR("PPV"), v3::bias_t::propositive)
				(NSTR("ASU+"), v3::bias_t::assurative_intensive)
				(NSTR("HPB+"), v3::bias_t::hyperbolic_intensive)
				(NSTR("COI+"), v3::bias_t::coincidental_intensive)
				(NSTR("ACP+"), v3::bias_t::acceptive_intensive)
				(NSTR("RAC+"), v3::bias_t::reactive_intensive)
				(NSTR("STU+"), v3::bias_t::stupefactive_intensive)
				(NSTR("CTV+"), v3::bias_t::contemplative_intensive)
				(NSTR("DPV+"), v3::bias_t::desperative_intensive)
				(NSTR("RVL+"), v3::bias_t::revelative_intensive)
				(NSTR("GRT+"), v3::bias_t::gratificative_intensive)
				(NSTR("SOL+"), v3::bias_t::solicitive_intensive)
				(NSTR("SEL+"), v3::bias_t::selective_intensive)
				(NSTR("IRO+"), v3::bias_t::ironic_intensive)
				(NSTR("EXA+"), v3::bias_t::exasperative_intensive)
				(NSTR("LTL+"), v3::bias_t::literal_intensive)
				(NSTR("CRR+"), v3::bias_t::corrective_intensive)
				(NSTR("EUP+"), v3::bias_t::euphemistic_intensive)
				(NSTR("SKP+"), v3::bias_t::skeptical_intensive)
				(NSTR("CYN+"), v3::bias_t::cynical_intensive)
				(NSTR("CTP+"), v3::bias_t::contemptive_intensive)
				(NSTR("DSM+"), v3::bias_t::dismissive_intensive)
				(NSTR("IDG+"), v3::bias_t::indignative_intensive)
				(NSTR("SGS+"), v3::bias_t::suggestive_intensive)
				(NSTR("PPV+"), v3::bias_t::propositive_intensive)
		};

#pragma warning(default : 4834)

	}
}
