#include <postgres.h>
#include <utils/builtins.h>

#include "src/utils.c"

int64_t cell_reference_count(const uint_fast8_t* cell, uint_fast32_t len);
uint_fast8_t* cell_hash_repr(const uint_fast8_t* cell, uint_fast32_t len);

PG_MODULE_MAGIC;

/// bytes -> int
PG_FUNCTION_INFO_V1(cell_root_refs);
/// bytea -> text
PG_FUNCTION_INFO_V1(cell_root_hash);


Datum
cell_root_refs(PG_FUNCTION_ARGS) {
    bytea *data = PG_GETARG_BYTEA_P(0);
    const uint_fast8_t *bytes = (uint_fast8_t *) VARDATA_ANY(data);
    uint_fast32_t size = VARSIZE_ANY_EXHDR(data);
    PG_RETURN_UINT32(cell_reference_count(bytes, size));
}


Datum
cell_root_hash(PG_FUNCTION_ARGS) {
    bytea *data = PG_GETARG_BYTEA_P(0);
    const uint_fast8_t *bytes = (uint_fast8_t *) VARDATA_ANY(data);
    uint_fast32_t size = VARSIZE_ANY_EXHDR(data);
    const char *data_cell_hash = bytes2hex(cell_hash_repr(bytes, size), SHA256_SIZE);
    PG_RETURN_TEXT_P(cstring_to_text(data_cell_hash));
}