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
    expat.dev
    libxml2.dev
    xorg.libXext.dev
    xorg.libX11.dev
    xorg.libxcb.dev
    xorg.libXdmcp.dev
    xorg.libXau.dev
    libpthread-stubs
    xcb-proto
    xorg.xtrans
    xorg.xorgproto
    # (callPackage ./nix/nzsl.nix {})

    vulkan-headers
    vulkan-tools
    vulkan-loader
    vulkan-validation-layers

    clang-tools

    python313Full.debug
    sdl3.dev

    xmake
  ];
}
