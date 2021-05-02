#pragma once

#include <boost/bimap.hpp>
#include <boost/bimap/unordered_set_of.hpp>
#include <boost/bimap/unordered_multiset_of.hpp>

#include "morphology.h"
#include "serialize.h"

namespace ithkuil
{
	namespace v3
	{
		namespace slot
		{
			template<typename Value>
			using slot_smap_t = boost::bimap<boost::bimaps::unordered_set_of<v3::serialized_t>, boost::bimaps::unordered_set_of<Value>>;
			template<typename Value>
			using slot_mmap_t = boost::bimap<boost::bimaps::unordered_set_of<v3::serialized_t>, boost::bimaps::unordered_multiset_of<Value>>;

			using cv_map_t = slot_smap_t<v3::newslot::cv::packed_t>;
			using vl_map_t = slot_mmap_t<v3::valence>;
			using cg_map_t = slot_smap_t<v3::validation>;
			using cs_map_t = slot_smap_t<v3::newslot::cs::packed_t>;
			using vr_map_t = slot_mmap_t<v3::newslot::vr::packed_t>;
			using vp_map_t = slot_mmap_t<v3::newslot::vp::packed_t>;
			using ca_map_t = slot_mmap_t<v3::newslot::ca::packed_t>;
			using vf_map_t = slot_mmap_t<v3::newslot::vf::packed_t>;
			using cb_map_t = slot_smap_t<v3::bias>;
			using su_map_t = slot_mmap_t<v3::suffix>;
			using vx_map_t = slot_mmap_t<v3::newslot::vx::packed_t>;
			using vc_map_t = slot_mmap_t<v3::case_>;
			using civi_map_t = slot_mmap_t<v3::newslot::civi::packed_t>;
			using vm_map_t = slot_mmap_t<v3::modality>;
			using vs_map_t = slot_mmap_t<v3::aspect>;


			inline cv_map_t cv_map;
			inline vl_map_t vl_map;
			inline cg_map_t cg_map;
			inline cs_map_t cs_map;
			inline vr_map_t vr_map;
			inline vp_map_t vp_map;
			inline ca_map_t ca_map;
			inline vf_map_t vf_map;
			inline cb_map_t cb_map;
			inline su_map_t su_map;
			inline vx_map_t vx_map;
			inline vc_map_t vc1_map;
			inline vc_map_t vc2_map;
			inline civi_map_t civi_map;
			inline vm_map_t vm_map;
			inline vs_map_t vs_map;
		}
	}
}
