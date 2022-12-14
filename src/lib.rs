#[no_mangle]
pub extern "C" fn cell_reference_count(cell: *const u8, len: usize) -> i64 {
    let cell = unsafe { std::slice::from_raw_parts(cell, len) };
    let cell = everscale_types::ArcBoc::decode(cell).unwrap();
    cell.reference_count() as i64
}

#[no_mangle]
pub extern "C" fn cell_hash_repr(cell: *const u8, len: usize) ->  *const u8 {
    let cell = unsafe { std::slice::from_raw_parts(cell, len) };
    let cell = everscale_types::ArcBoc::decode(cell).unwrap();
    let ptr = cell.repr_hash().as_ptr();
    std::mem::forget(cell);
    ptr
}