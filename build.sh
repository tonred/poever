cargo build --release
(cd ./extension && make clean)
cp ./target/release/libpoever.a ./extension
(cd ./extension && make && make install)