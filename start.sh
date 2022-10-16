emcc="C:\\Users\\ethan\\emsdk\\upstream\\emscripten\\em++"
node="C:\\Program Files\\nodejs\\node.exe"

assets="assets"

output_wasm="static\\main_wasm.js"
output_fallback="static\\main_fallback.js"

object_options="--std=c++17 -O3"
linker_options="$object_options -sUSE_WEBGL2=1 -sMIN_WEBGL_VERSION=2 -sFULL_ES3=1 -sEXPORT_ALL --preload-file $assets"

build_side_module() {
  local src="src\\$2.cpp"
  local build="build\\$2.o"

  input="$input $build"
  if (( $1 == 1 )); then
    $emcc $object_options -sSIDE_MODULE=1 -c -o $build $src
  fi
}

build_main_module() {
  local src="src\\$2.cpp"
  local build="build\\$2.o"

  input="$input $build"
  if (( $1 == 1 )); then
    $emcc $object_options -sMAIN_MODULE=1 -c -o $build $src
  fi
}

build_all_simple() {
  local src="src\\$1.cpp"

  $emcc $linker_options -sWASM=1 -o $output_wasm $src
  $emcc $linker_options -sWASM=0 -o $output_fallback $src
}

build_all_pedantic() {
  local input=""

  build_side_module 0 "Block"
  build_side_module 0 "BlockMesh"
  build_side_module 0 "BlockType"
  build_side_module 0 "Chunk"
  build_side_module 0 "ChunkIteratorX"
  build_side_module 0 "ChunkIteratorY"
  build_side_module 0 "ChunkIteratorZ"
  build_side_module 0 "ChunkMesh"
  build_side_module 0 "Hash"
  build_side_module 0 "Helper"
  build_side_module 0 "Ivec2"
  build_side_module 0 "Ivec3"
  build_side_module 0 "Ivec4"
  build_side_module 0 "Noise"
  build_side_module 0 "Point"
  build_side_module 0 "Triangle"
  build_side_module 0 "Vec2"
  build_side_module 0 "Vec3"
  build_side_module 0 "Vec4"
  build_side_module 0 "World"
  build_side_module 0 "WorldMesh"

  build_main_module 0 "$1"

  $emcc $linker_options -sWASM=1 -o $output_wasm $input
  $emcc $linker_options -sWASM=0 -o $output_fallback $input
}

# build_all_simple "main"
build_all_pedantic "main"

"$node" "index.js"