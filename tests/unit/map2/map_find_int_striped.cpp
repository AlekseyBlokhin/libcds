//$$CDS-header$$

#include "map2/map_find_int.h"
#include "map2/map_type_striped.h"

#undef TEST_CASE
#define TEST_CASE(TAG, X)  void Map_find_int::X() { run_test<typename map_type< TAG, key_type, value_type>::X>(); }
#include "map2/map_defs.h"

namespace map2 {
    CDSUNIT_DECLARE_StripedMap
    CDSUNIT_DECLARE_RefinableMap
} // namespace map2
