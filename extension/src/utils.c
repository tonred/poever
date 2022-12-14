const uint_fast32_t SHA256_SIZE = 32;

inline char *prepare_char_array(uint_fast32_t size) {
    char *array;
    if (!(array = palloc(size + 1))) {
        ereport(ERROR, (
                errcode(ERRCODE_OUT_OF_MEMORY),
                        errmsg("Not enough memory"),
                        errdetail("Not enough memory for hex representation of uint8* data with size is %u", size),
                        errhint("99%% is due to fucking memory leaks, or see `prepare_char_array`")
        ));
    }
    array[size] = 0;
    return array;
}

char *bytes2hex(const uint_fast8_t *bytes, uint_fast32_t size) {
    char *hex = prepare_char_array(2 * size * sizeof(char));
    char hex_str[] = "0123456789abcdef";
    for (uint_fast32_t i = 0; i < size; i++) {
        hex[i * 2 + 0] = hex_str[(bytes[i] >> 4) & 0x0F];
        hex[i * 2 + 1] = hex_str[(bytes[i]) & 0x0F];
    }
    return hex;
}