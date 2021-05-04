// refactored code

#include <tuple>
#include <boost/bimap.hpp>
#include <boost/bimap/unordered_set_of.hpp>
#include "nstring.h"
#include "include/ithlib/morphology.h"

namespace ithkuil
{
	namespace v3
	{
		template<typename T>
		using abbreviation_map_for = boost::bimap<boost::bimaps::unordered_set_of<nstring>, boost::bimaps::unordered_set_of<T>>;

		template<typename... Ts>
		using abbreviations_base = std::tuple<abbreviation_map_for<Ts>...>;

		using abbreviations_map_t = abbreviations_base<
			configuration_t,
			affiliation_t,
			perspective_t,
			extension_t,
			essence_t,
			pattern_t,
			stem_t,
			function_t,
			context_t,
			format,
			bias_t,
			version_t,
			ccase_t,
			mood_t,
			designation_t,
			relation_t,
			phase_t,
			sanction_t,
			illocution_t,
			valence_t,
			validation_t,
			aspect_t
		>;

		template<typename T>
		constexpr T& get(abbreviations_map_t& abbr) noexcept
		{
			return std::get<abbreviation_map_for<T>>();
		}

		template<typename T>
		constexpr T&& get(abbreviations_map_t&& abbr) noexcept
		{
			return std::get<abbreviation_map_for<T>>();
		}

		template<typename T>
		constexpr const T& get(const abbreviations_map_t& abbr) noexcept
		{
			return std::get<abbreviation_map_for<T>>();
		}

		template<typename T>
		constexpr const T&& get(const abbreviations_map_t&& abbr) noexcept
		{
			return std::get<abbreviation_map_for<T>>();
		}

		class language_state_t
		{
		};
	}
}