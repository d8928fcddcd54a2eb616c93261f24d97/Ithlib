#pragma once
#include <unordered_map>
#include <string>
#include "morphology.h"

#define DEFINE_MAP(category) inline std::unordered_map<std::wstring, category> category ## _map
#pragma warning(disable : 4244)
namespace ithkuil
{
	namespace v3
	{
		namespace notation
		{
			DEFINE_MAP(phase)
			{
				{ L"CTX", phase::contextual },
				{ L"PCT", phase::punctual },
				{ L"ITR", phase::iterative },
				{ L"REP", phase::repetitive },
				{ L"ITM", phase::intermittent },
				{ L"RCT", phase::recurrent },
				{ L"FRE", phase::frequentative },
				{ L"FRG", phase::fragmentative },
				{ L"FLC", phase::fluctuative }
			};

			DEFINE_MAP(sanction)
			{
				{ L"PPS", sanction::propositional },
				{ L"EPI", sanction::epistemic },
				{ L"ALG", sanction::allegative },
				{ L"IPU", sanction::imputative },
				{ L"RFU", sanction::refutative },
				{ L"REB", sanction::rebuttative },
				{ L"THR", sanction::theoretical },
				{ L"EXV", sanction::expatiative },
				{ L"AXM", sanction::axiomatic }
			};

			DEFINE_MAP(illocution)
			{
				{ L"ASR", illocution::assertive },
				{ L"IRG", illocution::interrogative },
				{ L"DIR", illocution::directive },
				{ L"ADM", illocution::admonitive },
				{ L"HOR", illocution::hortative },
				{ L"DEC", illocution::declarative }
			};

			DEFINE_MAP(configuration)
			{
				{ L"UNI", v3::configuration::uniplex },
				{ L"DPX", v3::configuration::duplex },
				{ L"DCT", v3::configuration::discrete },
				{ L"AGG", v3::configuration::aggregative },
				{ L"SEG", v3::configuration::segmentative },
				{ L"CPN", v3::configuration::componential },
				{ L"COH", v3::configuration::coherent },
				{ L"CST", v3::configuration::composite },
				{ L"MLT", v3::configuration::multiform }
			};

			DEFINE_MAP(affiliation)
			{
				{ L"ASO", v3::affiliation::associative },
				{ L"VAR", v3::affiliation::variative },
				{ L"COA", v3::affiliation::coalescent },
				{ L"CSL", v3::affiliation::consolidative }
			};

			DEFINE_MAP(essence)
			{
				{ L"NRM", v3::essence::normal },
				{ L"RPV", v3::essence::representative }
			};

			DEFINE_MAP(extension)
			{
				{ L"DEL", v3::extension::delimitive },
				{ L"DPL", v3::extension::depletive },
				{ L"GRA", v3::extension::graduative },
				{ L"ICP", v3::extension::inceptive },
				{ L"PRX", v3::extension::proximal },
				{ L"TRM", v3::extension::terminative },
			};

			DEFINE_MAP(perspective)
			{
				{ L"M", v3::perspective::monadic },
				{ L"A", v3::perspective::abstract },
				{ L"N", v3::perspective::nomic },
				{ L"U", v3::perspective::unbounded }
			};

			DEFINE_MAP(aspect)
			{
				{ L"A_0", v3::aspect::none },
				{ L"RTR", v3::aspect::retrospective },
				{ L"PRS", v3::aspect::prospective },
				{ L"HAB", v3::aspect::habitual },
				{ L"PRG", v3::aspect::progressive },
				{ L"IMM", v3::aspect::imminent },
				{ L"PCS", v3::aspect::precessive },
				{ L"REG", v3::aspect::regulative },
				{ L"EXP", v3::aspect::experiential },
				{ L"RSM", v3::aspect::resumptive },
				{ L"CSS", v3::aspect::cessative },
				{ L"RCS", v3::aspect::recessative },
				{ L"PAU", v3::aspect::pausal },
				{ L"RGR", v3::aspect::regressive },
				{ L"PCL", v3::aspect::preclusive },
				{ L"CNT", v3::aspect::continuative },
				{ L"ICS", v3::aspect::incessative },
				{ L"PMP", v3::aspect::preemptive },
				{ L"CLM", v3::aspect::climactic },
				{ L"PTC", v3::aspect::protractive },
				{ L"TMP", v3::aspect::temporary },
				{ L"MTV", v3::aspect::motive },
				{ L"CSQ", v3::aspect::consequential },
				{ L"SQN", v3::aspect::sequential },
				{ L"EPD", v3::aspect::expeditive },
				{ L"DCL", v3::aspect::disclusive },
				{ L"CCL", v3::aspect::conclusive },
				{ L"CUL", v3::aspect::culminative },
				{ L"IMD", v3::aspect::intermediative },
				{ L"TRD", v3::aspect::tardative },
				{ L"TNS", v3::aspect::transitional },
				{ L"ITC", v3::aspect::intercommutative },
				{ L"CSM", v3::aspect::consumptive }
			};

			DEFINE_MAP(mood)
			{
				{ L"FAC", v3::mood::factual },
				{ L"SUB", v3::mood::subjunctive },
				{ L"ASM", v3::mood::assumptive },
				{ L"SPC", v3::mood::speculative },
				{ L"COU", v3::mood::counterfactive },
				{ L"HYP", v3::mood::hypothetical },
				{ L"IPL", v3::mood::implicative },
				{ L"ASC", v3::mood::ascriptive }
			};

			DEFINE_MAP(valence)
			{
				{ L"MNO", v3::valence::monoactive },
				{ L"PRL", v3::valence::parallel },
				{ L"CRO", v3::valence::corollary },
				{ L"RCP", v3::valence::reciprocal },
				{ L"CPL", v3::valence::complementary },
				{ L"NNR", v3::valence::nonrelational },
				{ L"DUP", v3::valence::duplicative },
				{ L"DEM", v3::valence::demonstrative },
				{ L"RES", v3::valence::resistive },
				{ L"IMT", v3::valence::imitative },
				{ L"CNG", v3::valence::contingent },
				{ L"PTI", v3::valence::participative },
				{ L"IDC", v3::valence::indicative },
				{ L"MUT", v3::valence::mutual }
			};

			DEFINE_MAP(validation)
			{
				{ L"CNF", v3::validation::confirmative },
				{ L"AFM", v3::validation::affirmative },
				{ L"RPT", v3::validation::reportive },
				{ L"INF", v3::validation::inferential },
				{ L"ITU", v3::validation::intuitive },
				{ L"PSM", v3::validation::presumptive },
				{ L"PSM2", v3::validation::presumptive2 },
				{ L"PPT", v3::validation::purportive },
				{ L"PPT2", v3::validation::purportive2 },
				{ L"CJT", v3::validation::conjectural },
				{ L"DUB", v3::validation::dubitative },
				{ L"TEN", v3::validation::tentative },
				{ L"PUT", v3::validation::putative },
				{ L"IPB", v3::validation::improbable },
			};

			DEFINE_MAP(function)
			{
				{ L"STA", v3::function::stative },
				{ L"DYN", v3::function::dynamic },
				{ L"MNF", v3::function::manifestive },
				{ L"DSC", v3::function::descriptive },
			};

			DEFINE_MAP(pattern_t)
			{
				{ L"P_1", 1 },
				{ L"P_2", 2 },
				{ L"P_3", 3 },
			};

			DEFINE_MAP(stem_t)
			{
				{ L"S_1", 1 },
				{ L"S_2", 2 },
				{ L"S_3", 3 },
			};

			DEFINE_MAP(designation)
			{
				{ L"IFL", v3::designation::informal },
				{ L"FML", v3::designation::formal }
			};

			DEFINE_MAP(context)
			{
				{ L"EXS", v3::context::existential },
				{ L"FNC", v3::context::functional },
				{ L"RPS", v3::context::representational },
				{ L"AMG", v3::context::amalgamate },
			};

			DEFINE_MAP(format)
			{
				{ L"F_0", v3::format::none },
				{ L"SCH", v3::format::schematic },
				{ L"ISR", v3::format::instrumentative },
				{ L"ATH", v3::format::authoritive },
				{ L"RSL", v3::format::resultative },
				{ L"SBQ", v3::format::subsequent },
				{ L"CCM", v3::format::concommitant },
				{ L"OBJ", v3::format::objective },
				{ L"PRT", v3::format::precurrent },
				{ L"AFI", v3::format::affinitive },
			};

			DEFINE_MAP(bias)
			{
				{ L"ASU", v3::bias::assurative },
				{ L"HPB", v3::bias::hyperbolic },
				{ L"COI", v3::bias::coincidental },
				{ L"ACP", v3::bias::acceptive },
				{ L"RAC", v3::bias::reactive },
				{ L"STU", v3::bias::stupefactive },
				{ L"CTV", v3::bias::contemplative },
				{ L"DPV", v3::bias::desperative },
				{ L"RVL", v3::bias::revelative },
				{ L"GRT", v3::bias::gratificative },
				{ L"SOL", v3::bias::solicitive },
				{ L"SEL", v3::bias::selective },
				{ L"IRO", v3::bias::ironic },
				{ L"EXA", v3::bias::exasperative },
				{ L"LTL", v3::bias::literal },
				{ L"CRR", v3::bias::corrective },
				{ L"EUP", v3::bias::euphemistic },
				{ L"SKP", v3::bias::skeptical },
				{ L"CYN", v3::bias::cynical },
				{ L"CTP", v3::bias::contemptive },
				{ L"DSM", v3::bias::dismissive },
				{ L"IDG", v3::bias::indignative },
				{ L"SGS", v3::bias::suggestive },
				{ L"PPV", v3::bias::propositive },
				{ L"ASU+", v3::bias::assurative_intensive },
				{ L"HPB+", v3::bias::hyperbolic_intensive },
				{ L"COI+", v3::bias::coincidental_intensive },
				{ L"ACP+", v3::bias::acceptive_intensive },
				{ L"RAC+", v3::bias::reactive_intensive },
				{ L"STU+", v3::bias::stupefactive_intensive },
				{ L"CTV+", v3::bias::contemplative_intensive },
				{ L"DPV+", v3::bias::desperative_intensive },
				{ L"RVL+", v3::bias::revelative_intensive },
				{ L"GRT+", v3::bias::gratificative_intensive },
				{ L"SOL+", v3::bias::solicitive_intensive },
				{ L"SEL+", v3::bias::selective_intensive },
				{ L"IRO+", v3::bias::ironic_intensive },
				{ L"EXA+", v3::bias::exasperative_intensive },
				{ L"LTL+", v3::bias::literal_intensive },
				{ L"CRR+", v3::bias::corrective_intensive },
				{ L"EUP+", v3::bias::euphemistic_intensive },
				{ L"SKP+", v3::bias::skeptical_intensive },
				{ L"CYN+", v3::bias::cynical_intensive },
				{ L"CTP+", v3::bias::contemptive_intensive },
				{ L"DSM+", v3::bias::dismissive_intensive },
				{ L"IDG+", v3::bias::indignative_intensive },
				{ L"SGS+", v3::bias::suggestive_intensive },
				{ L"PPV+", v3::bias::propositive_intensive }
			};

			DEFINE_MAP(suffix)
			{
				{ L"DEF", v3::suffix::def },
				{ L"DSR", v3::suffix::dsr },
				{ L"INL", v3::suffix::inl },
				{ L"EXT", v3::suffix::ext },
				{ L"FAM", v3::suffix::fam },
				{ L"SIM", v3::suffix::sim },
				{ L"DEX", v3::suffix::dex },
				{ L"DXX", v3::suffix::dxx },
				{ L"SEQ", v3::suffix::seq },
				{ L"SQT", v3::suffix::sqt },
				{ L"SQC", v3::suffix::sqc },
				{ L"COO", v3::suffix::coo },
				{ L"CTR", v3::suffix::ctr },
				{ L"DST", v3::suffix::dst },
				{ L"TPI", v3::suffix::tpi },
				{ L"TPD", v3::suffix::tpd },
				{ L"FRQ", v3::suffix::frq },
				{ L"TPR", v3::suffix::tpr },
				{ L"TPP", v3::suffix::tpp },
				{ L"ATC", v3::suffix::atc },
				{ L"LAT", v3::suffix::lat },
				{ L"ITN", v3::suffix::itn },
				{ L"RPN", v3::suffix::rpn },
				{ L"CAL", v3::suffix::cal },
				{ L"DGR", v3::suffix::dgr },
				{ L"PTW", v3::suffix::ptw },
				{ L"PTT", v3::suffix::ptt },
				{ L"CNM", v3::suffix::cnm },
				{ L"SUF", v3::suffix::suf },
				{ L"EXN", v3::suffix::exn },
				{ L"EXD", v3::suffix::exd },
				{ L"RCO", v3::suffix::rco },
				{ L"TFI", v3::suffix::tfi },
				{ L"TFV", v3::suffix::tfv },
				{ L"CRI", v3::suffix::cri },
				{ L"CRV", v3::suffix::crv },
				{ L"MDL", v3::suffix::mdl },
				{ L"FLS", v3::suffix::fls },
				{ L"ICR", v3::suffix::icr },
				{ L"DCR", v3::suffix::dcr },
				{ L"ICD", v3::suffix::icd },
				{ L"DCI", v3::suffix::dci },
				{ L"IDR", v3::suffix::idr },
				{ L"MVT", v3::suffix::mvt },
				{ L"SIZ", v3::suffix::siz },
				{ L"SCO", v3::suffix::sco },
				{ L"AFT", v3::suffix::aft },
				{ L"QUA", v3::suffix::qua },
				{ L"UNQ", v3::suffix::unq },
				{ L"IPT", v3::suffix::ipt },
				{ L"CNQ", v3::suffix::cnq },
				{ L"NTR", v3::suffix::ntr },
				{ L"BEH", v3::suffix::beh },
				{ L"APR", v3::suffix::apr },
				{ L"HRC", v3::suffix::hrc },
				{ L"FRM", v3::suffix::frm },
				{ L"TYP", v3::suffix::typ },
				{ L"PTY", v3::suffix::pty },
				{ L"ITG", v3::suffix::itg },
				{ L"MDN", v3::suffix::mdn },
				{ L"NA1", v3::suffix::na1 },
				{ L"NA2", v3::suffix::na2 },
				{ L"NA3", v3::suffix::na3 },
				{ L"NA4", v3::suffix::na4 },
				{ L"PLV", v3::suffix::plv },
				{ L"DEV", v3::suffix::dev },
				{ L"REA", v3::suffix::rea },
				{ L"SCS", v3::suffix::scs },
				{ L"CAP", v3::suffix::cap },
				{ L"PRB", v3::suffix::prb },
				{ L"STR", v3::suffix::str },
				{ L"FRC", v3::suffix::frc },
				{ L"ITY", v3::suffix::ity },
				{ L"SPD", v3::suffix::spd },
				{ L"CFD", v3::suffix::cfd },
				{ L"EFI", v3::suffix::efi },
				{ L"ERR", v3::suffix::err },
				{ L"MAT", v3::suffix::mat },
				{ L"SBT", v3::suffix::sbt },
				{ L"DRC", v3::suffix::drc },
				{ L"SUD", v3::suffix::sud },
				{ L"PCN", v3::suffix::pcn },
				{ L"CNC", v3::suffix::cnc },
				{ L"SPH", v3::suffix::sph },
				{ L"CVT", v3::suffix::cvt },
				{ L"EFT", v3::suffix::eft },
				{ L"DSG", v3::suffix::dsg },
				{ L"DCS", v3::suffix::dcs },
				{ L"CTN", v3::suffix::ctn },
				{ L"PHY", v3::suffix::phy },
				{ L"MD01", v3::suffix::md01 },
				{ L"MD02", v3::suffix::md02 },
				{ L"MD03", v3::suffix::md03 },
				{ L"MD04", v3::suffix::md04 },
				{ L"MD05", v3::suffix::md05 },
				{ L"MD06", v3::suffix::md06 },
				{ L"MD07", v3::suffix::md07 },
				{ L"MD08", v3::suffix::md08 },
				{ L"MD09", v3::suffix::md09 },
				{ L"MD10", v3::suffix::md10 },
				{ L"MD11", v3::suffix::md11 },
				{ L"MD12", v3::suffix::md12 },
				{ L"MD13", v3::suffix::md13 },
				{ L"MD14", v3::suffix::md14 },
				{ L"MD15", v3::suffix::md15 },
				{ L"MD16", v3::suffix::md16 },
				{ L"MD17", v3::suffix::md17 },
				{ L"MD18", v3::suffix::md18 },
				{ L"MD19", v3::suffix::md19 },
				{ L"MD20", v3::suffix::md20 },
				{ L"MD21", v3::suffix::md21 },
				{ L"MD22", v3::suffix::md22 },
				{ L"MD23", v3::suffix::md23 },
				{ L"MD24", v3::suffix::md24 },
				{ L"MD25", v3::suffix::md25 },
				{ L"MD26", v3::suffix::md26 },
				{ L"MD27", v3::suffix::md27 },
				{ L"MD28", v3::suffix::md28 },
				{ L"MD29", v3::suffix::md29 },
				{ L"MD30", v3::suffix::md30 },
				{ L"MD31", v3::suffix::md31 },
				{ L"MD32", v3::suffix::md32 },
				{ L"MD33", v3::suffix::md33 },
				{ L"AGC", v3::suffix::agc },
				{ L"ROL", v3::suffix::rol },
				{ L"UTE", v3::suffix::ute },
				{ L"CNS", v3::suffix::cns },
				{ L"MEC", v3::suffix::mec },
				{ L"BOD", v3::suffix::bod },
				{ L"DBI", v3::suffix::dbi },
				{ L"SOC", v3::suffix::soc },
				{ L"OAU", v3::suffix::oau },
				{ L"AUT", v3::suffix::aut },
				{ L"RSN", v3::suffix::rsn },
				{ L"MTA", v3::suffix::mta },
				{ L"XPT", v3::suffix::xpt },
				{ L"DLB", v3::suffix::dlb },
				{ L"MOT", v3::suffix::mot },
				{ L"ENB", v3::suffix::enb },
				{ L"AGN", v3::suffix::agn },
				{ L"IMP", v3::suffix::imp },
				{ L"TPF", v3::suffix::tpf },
				{ L"SWR", v3::suffix::swr },
				{ L"PLA", v3::suffix::pla },
				{ L"APT", v3::suffix::apt },
				{ L"TEM", v3::suffix::tem },
				{ L"PTF", v3::suffix::ptf },
				{ L"PTG", v3::suffix::ptg },
				{ L"MET", v3::suffix::met },
				{ L"SSD", v3::suffix::ssd },
				{ L"SBS", v3::suffix::sbs },
				{ L"SPS", v3::suffix::sps },
				{ L"ATN", v3::suffix::atn },
				{ L"DPR", v3::suffix::dpr },
				{ L"SEP", v3::suffix::sep },
				{ L"SDP", v3::suffix::sdp },
				{ L"NEW", v3::suffix::new_ },
				{ L"COS", v3::suffix::cos },
				{ L"WAK", v3::suffix::wak },
				{ L"SCT", v3::suffix::sct },
				{ L"NNN", v3::suffix::nnn },
				{ L"LVL", v3::suffix::lvl },
				{ L"FNS", v3::suffix::fns },
				{ L"FMS", v3::suffix::fms },
				{ L"TRF", v3::suffix::trf },
				{ L"CVY", v3::suffix::cvy },
				{ L"FEA", v3::suffix::fea },
				{ L"STG", v3::suffix::stg },
				{ L"CGL", v3::suffix::cgl },
				{ L"INB", v3::suffix::inb },
				{ L"PLE", v3::suffix::ple },
				{ L"ACQ", v3::suffix::acq },
				{ L"TAL", v3::suffix::tal },
				{ L"RNC", v3::suffix::rnc },
				{ L"DPT", v3::suffix::dpt },
				{ L"ENG", v3::suffix::eng },
				{ L"OPF", v3::suffix::opf },
				{ L"MLR", v3::suffix::mlr },
				{ L"HG1", v3::suffix::hg1 },
				{ L"HG2", v3::suffix::hg2 },
				{ L"PHS", v3::suffix::phs },
				{ L"LCT", v3::suffix::lct },
				{ L"PXM", v3::suffix::pxm },
				{ L"CTC", v3::suffix::ctc },
				{ L"VWP", v3::suffix::vwp },
				{ L"FE01", v3::suffix::fe01 },
				{ L"FE02", v3::suffix::fe02 },
				{ L"FE03", v3::suffix::fe03 },
				{ L"FE04", v3::suffix::fe04 },
				{ L"FE05", v3::suffix::fe05 },
				{ L"FE06", v3::suffix::fe06 },
				{ L"FE07", v3::suffix::fe07 },
				{ L"FE08", v3::suffix::fe08 },
				{ L"FE09", v3::suffix::fe09 },
				{ L"FE10", v3::suffix::fe10 },
				{ L"FE11", v3::suffix::fe11 },
				{ L"FE12", v3::suffix::fe12 }
			};

			DEFINE_MAP(type_t)
			{
				{ L"T_1", 1 },
				{ L"T_2", 2 },
				{ L"T_3", 3 }
			};

			DEFINE_MAP(degree_t)
			{
				{ L"D_1", 1 },
				{ L"D_2", 2 },
				{ L"D_3", 3 },
				{ L"D_4", 4 },
				{ L"D_5", 5 },
				{ L"D_6", 6 },
				{ L"D_7", 7 },
				{ L"D_8", 8 },
				{ L"D_9", 9 },
			};

			DEFINE_MAP(case_)
			{
				{ L"OBL", v3::case_::oblique },
				{ L"IND", v3::case_::inducive },
				{ L"ABS", v3::case_::absolutive },
				{ L"ERG", v3::case_::ergative },
				{ L"EFF", v3::case_::effectuative },
				{ L"AFF", v3::case_::affective },
				{ L"DAT", v3::case_::dative },
				{ L"INS", v3::case_::instrumental },
				{ L"ACT", v3::case_::activative },
				{ L"DER", v3::case_::derivative },
				{ L"SIT", v3::case_::situative },
				{ L"POS", v3::case_::posessive },
				{ L"PRP", v3::case_::proprietive },
				{ L"GEN", v3::case_::genitive },
				{ L"ATT", v3::case_::attributive },
				{ L"PDC", v3::case_::productive },
				{ L"ITP", v3::case_::interpretative },
				{ L"OGN", v3::case_::originative },
				{ L"PAR", v3::case_::partitive },
				{ L"CRS", v3::case_::contrastive },
				{ L"CPS", v3::case_::compositive },
				{ L"PRD", v3::case_::predicative },
				{ L"MED", v3::case_::mediative },
				{ L"APL", v3::case_::applicative },
				{ L"PUR", v3::case_::purposive },
				{ L"CSD", v3::case_::considerative },
				{ L"ESS", v3::case_::essive },
				{ L"ASI", v3::case_::assimilative },
				{ L"FUN", v3::case_::functive },
				{ L"TFM", v3::case_::transformative },
				{ L"REF", v3::case_::referential },
				{ L"CLA", v3::case_::classificative },
				{ L"CNV", v3::case_::conductive },
				{ L"IDP", v3::case_::interdependent },
				{ L"BEN", v3::case_::benefactive },
				{ L"TSP", v3::case_::transpositive },
				{ L"CMM", v3::case_::commutative },
				{ L"COM", v3::case_::comitative },
				{ L"CNJ", v3::case_::conjunctive },
				{ L"UTL", v3::case_::utilitative },
				{ L"ABE", v3::case_::abessive },
				{ L"CVS", v3::case_::conversive },
				{ L"COR", v3::case_::correlative },
				{ L"DEP", v3::case_::dependent },
				{ L"PVS", v3::case_::provisional },
				{ L"PTL", v3::case_::postulative },
				{ L"CON", v3::case_::concessive },
				{ L"EXC", v3::case_::exceptive },
				{ L"AVR", v3::case_::aversive },
				{ L"CMP", v3::case_::comparative },
				{ L"SML", v3::case_::simultaneitive },
				{ L"ASS", v3::case_::assessive },
				{ L"CNR", v3::case_::concursive },
				{ L"ACS", v3::case_::acessive },
				{ L"DFF", v3::case_::diffusive },
				{ L"PER", v3::case_::periodic },
				{ L"PRO", v3::case_::prolapsive },
				{ L"PCV", v3::case_::precursive },
				{ L"PCR", v3::case_::postcursive },
				{ L"ELP", v3::case_::elapsive },
				{ L"ALP", v3::case_::allapsive },
				{ L"INP", v3::case_::interpolative },
				{ L"EPS", v3::case_::episodic },
				{ L"PLM", v3::case_::prolimitive },
				{ L"LIM", v3::case_::limitative },
				{ L"LOC", v3::case_::locative },
				{ L"ORI", v3::case_::orientative },
				{ L"PSV", v3::case_::procursive },
				{ L"ALL", v3::case_::allative },
				{ L"ABL", v3::case_::ablative },
				{ L"NAV", v3::case_::navigative },
				{ L"VOC", v3::case_::vocative },
				{ L"CMP1A", v3::case_::comparative1a },
				{ L"CMP2A", v3::case_::comparative2a },
				{ L"CMP3A", v3::case_::comparative3a },
				{ L"CMP4A", v3::case_::comparative4a },
				{ L"CMP5A", v3::case_::comparative5a },
				{ L"CMP6A", v3::case_::comparative6a },
				{ L"CMP7A", v3::case_::comparative7a },
				{ L"CMP8A", v3::case_::comparative8a },
				{ L"CMP1B", v3::case_::comparative1b },
				{ L"CMP2B", v3::case_::comparative2b },
				{ L"CMP3B", v3::case_::comparative3b },
				{ L"CMP4B", v3::case_::comparative4b },
				{ L"CMP5B", v3::case_::comparative5b },
				{ L"CMP6B", v3::case_::comparative6b },
				{ L"CMP7B", v3::case_::comparative7b },
				{ L"CMP8B", v3::case_::comparative8b },
				{ L"CMP1C", v3::case_::comparative1c },
				{ L"CMP2C", v3::case_::comparative2c },
				{ L"CMP3C", v3::case_::comparative3c },
				{ L"CMP4C", v3::case_::comparative4c },
				{ L"CMP5C", v3::case_::comparative5c },
				{ L"CMP6C", v3::case_::comparative6c },
				{ L"CMP7C", v3::case_::comparative7c },
				{ L"CMP8C", v3::case_::comparative8c }
			};

			DEFINE_MAP(modality)
			{
				{ L"M_0", v3::modality::none },
				{ L"DES", v3::modality::desiderative },
				{ L"ASP", v3::modality::aspirative },
				{ L"EPC", v3::modality::expectative },
				{ L"CRD", v3::modality::credential },
				{ L"REQ", v3::modality::requisitive },
				{ L"EXH", v3::modality::exhortative },
				{ L"OPR", v3::modality::opportunitive },
				{ L"CPC", v3::modality::capacitative },
				{ L"PRM", v3::modality::permissive },
				{ L"PTN", v3::modality::potential },
				{ L"CLS", v3::modality::compulsory },
				{ L"OBG", v3::modality::obligative },
				{ L"IMS", v3::modality::impositive },
				{ L"ADV", v3::modality::advocative },
				{ L"ITV", v3::modality::intentive },
				{ L"ANT", v3::modality::anticipative },
				{ L"DSP", v3::modality::dispositive },
				{ L"PRE", v3::modality::preparative },
				{ L"NEC", v3::modality::necessitative },
				{ L"DCV", v3::modality::decisive },
				{ L"PTV", v3::modality::proclivitive },
				{ L"VOL", v3::modality::voluntative },
				{ L"ACC", v3::modality::accordative },
				{ L"ICL", v3::modality::inclinative },
				{ L"CML", v3::modality::compulsive },
				{ L"DVR", v3::modality::divertive },
				{ L"DVT", v3::modality::devotive },
				{ L"PFT", v3::modality::preferential },
				{ L"IPS", v3::modality::impressional },
				{ L"PMS", v3::modality::promissory }
			};

			DEFINE_MAP(level)
			{
				{ L"LVL_000", v3::level::none },
				{ L"EQU_REL", v3::level::equative_relative },
				{ L"SUR_REL", v3::level::surpassive_relative },
				{ L"DFC_REL", v3::level::deficient_relative },
				{ L"OPT_REL", v3::level::optimal_relative },
				{ L"MIN_REL", v3::level::minimal_relative },
				{ L"SPL_REL", v3::level::superlative_relative },
				{ L"IFR_REL", v3::level::inferior_relative },
				{ L"SPQ_REL", v3::level::superequative_relative },
				{ L"SBE_REL", v3::level::subequative_relative },
				{ L"EQU_ABS", v3::level::equative_absolute },
				{ L"SUR_ABS", v3::level::surpassive_absolute },
				{ L"DFC_ABS", v3::level::deficient_absolute },
				{ L"OPT_ABS", v3::level::optimal_absolute },
				{ L"MIN_ABS", v3::level::minimal_absolute },
				{ L"SPL_ABS", v3::level::superlative_absolute },
				{ L"IFR_ABS", v3::level::inferior_absolute },
				{ L"SPQ_ABS", v3::level::superequative_absolute },
				{ L"SBE_ABS", v3::level::subequative_absolute }
			};

			DEFINE_MAP(version)
			{
				{ L"PRC", v3::version::processual },
				{ L"CPT", v3::version::completive },
				{ L"INE", v3::version::ineffectual },
				{ L"INC", v3::version::incompletive },
				{ L"PST", v3::version::positive },
				{ L"EFC", v3::version::effective }
			};
		}
	}
}
#pragma warning(default : 4244)

