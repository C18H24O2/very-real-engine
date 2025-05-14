{
  pkgs ? import <nixpkgs> {},
}:

pkgs.mkShell {
  buildInputs = with pkgs; [
    meson
    ninja
    pkg-config
    python3
    openssl.dev
    zlib.dev
    libuv.dev
    libffi.dev
    # xmake
  ];
}
