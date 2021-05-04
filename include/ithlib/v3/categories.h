// Categories
//

#ifndef ITHLIB_CATEGORIES_H
#define ITHLIB_CATEGORIES_H

#include <cstdint>

namespace ithkuil
{
	namespace v3
	{
		enum class pattern_t : std::uint8_t
		{
			p1,
			p2,
			p3
		};

		enum class stem_t : std::uint8_t
		{
			s1,
			s2,
			s3
		};

		enum class designation_t : std::uint8_t
		{
			informal,
			formal
		};

		enum class designated_stem_t : std::uint8_t
		{
			iflp1s1,
			iflp1s2,
			iflp1s3,
			iflp2s1,
			iflp2s2,
			iflp2s3,
			iflp3s1,
			iflp3s2,
			iflp3s3,
			fmlp1s1,
			fmlp1s2,
			fmlp1s3,
			fmlp2s1,
			fmlp2s2,
			fmlp2s3,
			fmlp3s1,
			fmlp3s2,
			fmlp3s3
		};

		enum class function_t : std::uint8_t
		{
			stative,
			dynamic,
			manifestive,
			descriptive
		};

		enum class configuration_t : std::uint8_t
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

		enum class affiliation_t : std::uint8_t
		{
			consolidative,
			associative,
			variative,
			coalescent
		};

		enum class perspective_t : std::uint8_t
		{
			monadic,
			unbounded,
			nomic,
			abstract
		};

		enum class extension_t : std::uint8_t
		{
			delimitive,
			proximal,
			inceptive,
			terminative,
			depletive,
			graduative
		};

		enum class essence_t : std::uint8_t
		{
			normal,
			representative
		};

		enum class context_t : std::uint8_t
		{
			existential,
			functional,
			representational,
			amalgamate
		};

		enum class version_t : std::uint8_t
		{
			processual,
			completive,
			ineffectual,
			incompletive,
			positive,
			effective
		};

		enum class format_t : std::uint8_t
		{
			none,
			schematic,
			instrumentative,
			authoritive,
			resultative,
			subsequent,
			concommitant,
			objective,
			precurrent,
			affinitive
		};

		enum class ccase_t : std::uint8_t
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

			// possessive

			possessive,
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

		enum class relation_t : std::uint8_t
		{
			unframed,
			framed
		};

		enum class illocution_t : std::uint8_t
		{
			assertive,
			directive,
			interrogative,
			admonitive,
			hortative,
			declarative
		};

		enum class mood_t : std::uint8_t
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

		enum class phase_t : std::uint8_t
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

		enum class sanction_t : std::uint8_t
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

		enum class valence_t : std::uint8_t
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

		enum class validation_t : std::uint8_t
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

		enum class aspect_t : std::uint8_t
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

		enum class modality_t : std::uint8_t
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

		enum class level_t : std::uint8_t
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

		enum class bias_t : std::uint8_t
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

		enum class referent_t : std::uint8_t
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

		enum class suffix_type_t
		{
			t1,
			t2,
			t3
		};

		enum class suffix_degree_t
		{
			d1,
			d2,
			d3,
			d4,
			d5,
			d6,
			d7,
			d8,
			d9
		};

		enum class suffix_t : std::uint16_t
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
	}

	namespace v31
	{
		enum class cregister_t : std::uint8_t
		{
			narrative,
			discursive,
			parenthetical,
			cogitant,
			impressionistic,
		};
	}
}

#endif // !ITHLIB_CATEGORIES_H
