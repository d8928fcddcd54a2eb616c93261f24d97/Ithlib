#pragma once

#include <vector>
#include <string>
#include <tuple>
#include <optional>
#include <variant>
#include <array>
#include <type_traits>
#include <iostream>
#include <stdexcept>
#include <cstdint>

namespace ithkuil
{
	namespace v3
	{
		enum class configuration : std::uint8_t
		{
			uniplex,
			duplex,
			discrete,
			aggregative,
			segmentative,
			componential,
			coherent,
			composite,
			multiform
		};

		enum class affiliation : std::uint8_t
		{
			consolidative,
			associative,
			variative,
			coalescent
		};

		enum class perspective : std::uint8_t
		{
			monadic,
			unbounded,
			nomic,
			abstract
		};

		enum class extension : std::uint8_t
		{
			delimitive,
			proximal,
			inceptive,
			terminative,
			depletive,
			graduative
		};

		enum class essence : std::uint8_t
		{
			normal,
			representative
		};

		enum class context : std::uint8_t
		{
			existential,
			functional,
			representational,
			amalgamate
		};

		enum class designation : std::uint8_t
		{
			informal,
			formal
		};

		enum class case_ : std::uint8_t
		{
			// transrelative

			oblique,
			inducive,
			absolutive,
			ergative,
			effectuative,
			affective,
			dative,
			instrumental,
			activative,
			derivative,
			situative,

			// posessive

			posessive,
			proprietive,
			genitive,
			attributive,
			productive,
			interpretative,
			originative,

			// associative

			partitive,
			contrastive,
			compositive,
			predicative,
			mediative,
			applicative,
			purposive,
			considerative,
			essive,
			assimilative,
			functive,
			transformative,
			referential,
			classificative,
			conductive,
			interdependent,
			benefactive,
			transpositive,
			commutative,
			comitative,
			conjunctive,
			utilitative,
			abessive,
			conversive,
			correlative,
			dependent,
			provisional,
			postulative,
			concessive,
			exceptive,
			aversive,
			comparative,

			// temporal
			simultaneitive,

			assessive,
			concursive,
			acessive,
			diffusive,
			periodic,
			prolapsive,
			precursive,
			postcursive,
			elapsive,
			allapsive,
			interpolative,
			episodic,
			prolimitive,
			limitative,

			// spatial

			locative,
			orientative,
			procursive,
			allative,
			ablative,
			navigative,

			// vocative

			vocative,

			// comparison cases

			comparative1a,
			comparative2a,
			comparative3a,
			comparative4a,
			comparative5a,
			comparative6a,
			comparative7a,
			comparative8a,
			comparative1b,
			comparative2b,
			comparative3b,
			comparative4b,
			comparative5b,
			comparative6b,
			comparative7b,
			comparative8b,
			comparative1c,
			comparative2c,
			comparative3c,
			comparative4c,
			comparative5c,
			comparative6c,
			comparative7c,
			comparative8c
		};

		enum class function : std::uint8_t
		{
			stative,
			dynamic,
			manifestive,
			descriptive
		};

		enum class mood : std::uint8_t
		{
			factual,
			subjunctive,
			assumptive,
			speculative,
			counterfactive,
			hypothetical,
			implicative,
			ascriptive
		};

		enum class illocution : std::uint8_t
		{
			assertive,
			directive,
			interrogative,
			admonitive,
			hortative,
			declarative
		};

		enum class relation : std::uint8_t
		{
			unframed,
			framed
		};

		enum class phase : std::uint8_t
		{
			contextual,
			punctual,
			iterative,
			repetitive,
			intermittent,
			recurrent,
			frequentative,
			fragmentative,
			fluctuative
		};

		enum class sanction : std::uint8_t
		{
			propositional,
			epistemic,
			allegative,
			imputative,
			refutative,
			rebuttative,
			theoretical,
			expatiative,
			axiomatic
		};

		enum class valence : std::uint8_t
		{
			monoactive,
			parallel,
			corollary,
			reciprocal,
			complementary,
			nonrelational,
			duplicative,
			demonstrative,
			resistive,
			imitative,
			contingent,
			participative,
			indicative,
			mutual
		};

		enum class version : std::uint8_t
		{
			processual,
			completive,
			ineffectual,
			incompletive,
			positive,
			effective
		};

		enum class validation : std::uint8_t
		{
			// non-hearsay

			confirmative,
			affirmative,
			reportive,
			inferential,
			intuitive,

			// hearsay

			presumptive,
			presumptive2,
			purportive,
			purportive2,
			conjectural,
			dubitative,
			tentative,
			putative,
			improbable
		};

		enum class aspect : std::uint8_t
		{
			none,
			retrospective,
			prospective,
			habitual,
			progressive,
			imminent,
			precessive,
			regulative,
			experiential,
			resumptive,
			cessative,
			recessative,
			pausal,
			regressive,
			preclusive,
			continuative,
			incessative,
			preemptive,
			climactic,
			protractive,
			temporary,
			motive,
			consequential,
			sequential,
			expeditive,
			disclusive,
			conclusive,
			culminative,
			intermediative,
			tardative,
			transitional,
			intercommutative,
			consumptive
		};

		enum class bias : std::uint8_t
		{
			none,
			assurative,
			hyperbolic,
			coincidental,
			acceptive,
			reactive,
			stupefactive,
			contemplative,
			desperative,
			revelative,
			gratificative,
			solicitive,
			selective,
			ironic,
			exasperative,
			literal,
			corrective,
			euphemistic,
			skeptical,
			cynical,
			contemptive,
			dismissive,
			indignative,
			suggestive,
			propositive,
			assurative_intensive = 0x21,
			hyperbolic_intensive,
			coincidental_intensive,
			acceptive_intensive,
			reactive_intensive,
			stupefactive_intensive,
			contemplative_intensive,
			desperative_intensive,
			revelative_intensive,
			gratificative_intensive,
			solicitive_intensive,
			selective_intensive,
			ironic_intensive,
			exasperative_intensive,
			literal_intensive,
			corrective_intensive,
			euphemistic_intensive,
			skeptical_intensive,
			cynical_intensive,
			contemptive_intensive,
			dismissive_intensive,
			indignative_intensive,
			suggestive_intensive,
			propositive_intensive,
		};

		enum class modality : std::uint8_t
		{
			none,
			desiderative,
			aspirative,
			expectative,
			credential,
			requisitive,
			exhortative,
			opportunitive,
			capacitative,
			permissive,
			potential,
			compulsory,
			obligative,
			impositive,
			advocative,
			intentive,
			anticipative,
			dispositive,
			preparative,
			necessitative,
			decisive,
			proclivitive,
			voluntative,
			accordative,
			inclinative,
			compulsive,
			divertive,
			devotive,
			preferential,
			impressional,
			promissory
		};

		enum class level : std::uint8_t
		{
			none,
			equative_relative,
			surpassive_relative,
			deficient_relative,
			optimal_relative,
			minimal_relative,
			superlative_relative,
			inferior_relative,
			superequative_relative,
			subequative_relative,
			equative_absolute,
			surpassive_absolute,
			deficient_absolute,
			optimal_absolute,
			minimal_absolute,
			superlative_absolute,
			inferior_absolute,
			superequative_absolute,
			subequative_absolute
		};

		// TODO Reorder
		enum class format : std::uint8_t
		{
			none,
			schematic,
			instrumentative,
			authoritive,
			resultative,
			subsequent,
			concommitant,
			objective,
			affinitive,
			precurrent
		};

		enum class register_ : std::uint8_t
		{
			narrative,
			discursive,
			parenthetical,
			cogitant,
			impressionistic,
		};

		enum class suffix : std::uint16_t
		{
			// demonstrative

			def,
			dsr,
			inl,
			ext,
			fam,
			sim,

			// deictic

			dex,
			dxx,

			// sequential

			seq,
			sqt,
			sqc,

			// coordinative

			coo,
			ctr,
			dst,

			// temporal

			tpi,
			tpd,
			frq,
			tpr,
			tpp,
			atc,
			lat,
			itn,
			rpn,
			cal,

			// quantifying

			dgr,
			ptw,
			ptt,
			cnm,
			suf,
			exn,
			exd,

			// modulative

			rco,
			tfi,
			tfv,
			cri,
			crv,
			mdl,
			fls,
			icr,
			dcr,
			icd,
			dci,
			idr,
			mvt,

			// qualifying

			siz,
			sco,
			aft,
			qua,
			unq,
			ipt,
			cnq,
			ntr,
			beh,
			apr,
			hrc,
			frm,
			typ,
			pty,
			itg,
			mdn,

			// modifying

			na1,
			na2,
			na3,
			na4,
			plv,
			dev,
			rea,
			scs,
			cap,
			prb,

			// adverbial

			str,
			frc,
			ity,
			spd,
			cfd,
			efi,
			err,
			mat,
			sbt,
			drc,
			sud,
			pcn,
			cnc,
			sph,
			cvt,
			eft,
			dsg,
			dcs,
			ctn,
			phy,

			// modality

			md01,
			md02,
			md03,
			md04,
			md05,
			md06,
			md07,
			md08,
			md09,
			md10,
			md11,
			md12,
			md13,
			md14,
			md15,
			md16,
			md17,
			md18,
			md19,
			md20,
			md21,
			md22,
			md23,
			md24,
			md25,
			md26,
			md27,
			md28,
			md29,
			md30,
			md31,
			md32,
			md33,

			// agential/participant

			agc,
			rol,
			ute,
			cns,
			mec,
			bod,
			dbi,
			soc,
			oau,
			aut,
			rsn,
			mta,
			xpt,
			dlb,
			mot,
			enb,
			agn,
			imp,

			// miscellaneous

			tpf,
			swr,
			pla,
			apt,
			tem,
			ptf,
			ptg,
			met,
			ssd,
			sbs,
			sps,
			atn,
			dpr,
			sep,
			sdp,
			new_,
			cos,
			wak,
			sct,
			nnn,
			lvl,
			fns,
			fms,
			trf,
			cvy,
			fea,
			stg,
			cgl,
			inb,
			ple,
			acq,
			tal,
			rnc,
			dpt,
			eng,
			opf,
			mlr,
			hg1,
			hg2,
			phs,

			// locational

			lct,
			pxm,
			ctc,
			vwp,

			// format expansion

			fe01,
			fe02,
			fe03,
			fe04,
			fe05,
			fe06,
			fe07,
			fe08,
			fe09,
			fe10,
			fe11,
			fe12
		};

		enum class referent : std::uint8_t
		{
			m1,
			m1_m2,
			m1_u2,
			m2,
			u2,
			ma3,
			ua3,
			collective,
			av,
			aind,
			mx,
			aimp,
			m1_ma3,
			m1_ua3,
			m2_ma3,
			m2_ua3,
			u2_ma3,
			u2_ua3,
			m1_m2_ma3,
			m1_m2_ua3,
			m1_u2_ma3,
			m1_u2_ua3,
			m1_mx,
			m1_m2_mx,
			m1_u2_mx,
			m2_mx,
			u2_mx,
			mi3,
			ui3,
			abstract,
			uvsi3,
			indi3,
			obviative,
			impi3,
			m1_mi3,
			m1_ui3,
			m2_mi3,
			m2_ui3,
			u2_mi3,
			u2_ui3,
			m1_m2_mi3,
			m1_m2_ui3,
			m1_u2_mi3,
			m1_u2_ui3
		};

		// optional via 0
		using root_t = std::uint32_t;
		// starts with 1
		using stem_t = std::uint8_t;
		// starts with 1
		using pattern_t = std::uint8_t;
		// starts with 1
		using type_t = std::uint8_t;
		// starts with 1
		using degree_t = std::uint8_t;
		// optional via 0, starts with 1
		using topic_idx_t = std::uint8_t;

		struct vxc
		{
			type_t _type;
			degree_t _degree;
			suffix _suffix;
		};

		enum class vc_mutation : std::uint8_t
		{
			none,
			u_intact,
			u_mutated,
			i_diphtong
		};

		enum class civi_mutation : std::uint8_t
		{
			none,
			w_value,
			y_intact,
			y_mutated
		};

		// TODO consider bitfields

		struct formative
		{
			root_t root;
			root_t inc_root;
			pattern_t pttn;
			stem_t stem;
			designation dsgn;
			relation rltn;
			configuration cnfg;
			affiliation affn;
			perspective prsp;
			extension extn;
			essence essc;
			function fncn;
			context cntx;
			pattern_t inc_pttn;
			stem_t inc_stem;
			designation inc_dsgn;
			format frmt;
			case_ _case;
			std::vector<case_> inc_cases;
			std::vector<vxc> vxcs;
			std::optional<std::tuple<perspective, configuration>> inc_pc;
			mood _mood;
			sanction sncn;
			phase phse;
			illocution illn;
			valence vlnc;
			version vrsn;
			validation vldn;
			aspect aspt1;
			aspect aspt2;
			bias _bias;
		};

		struct srpr_opt
		{
			affiliation _affiliation;
			configuration _configuration;
			essence _essence;
			bias _bias;
			std::vector<vxc> _vxcs;
		};

		struct srpr_adjunct
		{
			referent _referent;
			case_ _case;
			std::variant<std::monostate, srpr_opt, case_> _opt;
		};

		struct drpr_opt
		{
			affiliation _affiliation1;
			configuration _configuration1;
			bias _bias;
		};

		struct drpr_adjunct
		{
			referent _referent1;
			referent _referent2;
			affiliation _affiliation2;
			configuration _configuration2;
			case_ _case1;
			case_ _case2;
			essence _essence1;
			essence _essence2;
			std::optional<drpr_opt> _opt;
		};

		struct case_adjunct
		{
			case_ _case;
			topic_idx_t _tidx;
		};

		using form = std::variant<formative, srpr_adjunct, drpr_adjunct, vxc, bias, aspect>;
	}
}
