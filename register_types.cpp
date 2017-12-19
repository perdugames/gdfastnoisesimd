/* register_types.cpp */

#include "error_macros.h"
#include "class_db.h"
#include "register_types.h"

#include "gdfastnoisesimd.h"

void register_gdfastnoisesimd_types() {
	ClassDB::register_class<GDFastNoiseSIMD>();

}

void unregister_gdfastnoisesimd_types() {
	// Do not do anything here.

}
