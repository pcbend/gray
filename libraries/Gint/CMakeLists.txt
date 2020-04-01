




ROOT_GENERATE_DICTIONARY(G__Gint Gint.h LINKDEF LinkDef.h)

add_library(Gint SHARED Gint.cxx G__Gint.cxx)

target_link_libraries(Gint ${ROOT_LIBRARIES})








