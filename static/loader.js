var Module = {};

const canvas = document.getElementById("canvas");
(window.onresize = function() {
  canvas.width = window.innerWidth;
  canvas.height = window.innerHeight;
})();
Module.canvas = canvas;

const script = document.createElement("script");
if (window.WebAssembly !== undefined) {
  console.log("Loading WASM...");
  const xhr = new XMLHttpRequest();
  xhr.open("GET", "main_wasm.wasm", true);
  xhr.responseType = "arraybuffer";
  xhr.onload = function() {
    Module.wasmBinary = xhr.response;
    script.src = "main_wasm.js";
    document.body.appendChild(script);
  }
  xhr.send();
} else {
  console.log("Loading fallback...");
  script.src = "main_fallback.js";
  document.body.appendChild(script);
}