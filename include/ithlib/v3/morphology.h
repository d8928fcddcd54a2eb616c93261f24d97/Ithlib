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

#include "categories.h"

namespace ithkuil
{
	namespace v3
	{
		
	//	using type_t = std::uint8_t;
	//	// starts with 1
	//	using degree_t = std::uint8_t;
	//	// optional via 0, starts with 1
	//	using topic_idx_t = std::uint8_t;

	//	struct vxc
	//	{
	//		type_t _type;
	//		degree_t _degree;
	//		suffix_t _suffix;
	//	};

	//	enum class vc_mutation : std::uint8_t
	//	{
	//		none,
	//		u_intact,
	//		u_mutated,
	//		i_diphtong
	//	};

	//	enum class civi_mutation : std::uint8_t
	//	{
	//		none,
	//		w_value,
	//		y_intact,
	//		y_mutated
	//	};

	//	// TODO consider bitfields

	//	struct formative
	//	{
	//		root_t root;
	//		root_t inc_root;
	//		pattern_t pttn;
	//		stem_t stem;
	//		designation_t dsgn;
	//		relation_t rltn;
	//		configuration_t cnfg;
	//		affiliation_t affn;
	//		perspective_t prsp;
	//		extension_t extn;
	//		essence_t essc;
	//		function_t fncn;
	//		context_t cntx;
	//		pattern_t inc_pttn;
	//		stem_t inc_stem;
	//		designation_t inc_dsgn;
	//		format_t frmt;
	//		ccase_t _case;
	//		std::vector<ccase_t> inc_cases;
	//		std::vector<vxc> vxcs;
	//		std::optional<std::tuple<perspective_t, configuration_t>> inc_pc;
	//		mood_t _mood;
	//		sanction_t sncn;
	//		phase_t phse;
	//		illocution_t illn;
	//		valence_t vlnc;
	//		version_t vrsn;
	//		validation_t vldn;
	//		aspect_t aspt1;
	//		aspect_t aspt2;
	//		bias_t _bias;
	//	};

	//	struct srpr_opt
	//	{
	//		affiliation_t _affiliation;
	//		configuration_t _configuration;
	//		essence_t _essence;
	//		bias_t _bias;
	//		std::vector<vxc> _vxcs;
	//	};

	//	struct srpr_adjunct
	//	{
	//		referent_t _referent;
	//		case_t _case;
	//		std::variant<std::monostate, srpr_opt, case_t> _opt;
	//	};

	//	struct drpr_opt
	//	{
	//		affiliation_t _affiliation1;
	//		configuration_t _configuration1;
	//		bias_t _bias;
	//	};

	//	struct drpr_adjunct
	//	{
	//		referent_t _referent1;
	//		referent_t _referent2;
	//		affiliation_t _affiliation2;
	//		configuration_t _configuration2;
	//		ccase_t _case1;
	//		ccase_t _case2;
	//		essence_t _essence1;
	//		essence_t _essence2;
	//		std::optional<drpr_opt> _opt;
	//	};

	//	struct case_adjunct
	//	{
	//		ccase_t _case;
	//		topic_idx_t _tidx;
	//	};

	//	using form = std::variant<formative, srpr_adjunct, drpr_adjunct, vxc, bias_t, aspect_t>;
	}
}
