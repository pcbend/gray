




ROOT_GENERATE_DICTIONARY(G__GInt GInt.h LINKDEF LinkDef.h)

add_library(GInt SHARED GInt.cxx G__GInt.cxx)

target_link_libraries(GInt ${ROOT_LIBRARIES})








