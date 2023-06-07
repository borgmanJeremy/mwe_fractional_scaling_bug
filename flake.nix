{
  description = "MWE flake build";

  inputs = {
    nixpkgs.url = "github:NixOS/nixpkgs/22.11";
    
    utils.url = "github:numtide/flake-utils";
    utils.inputs.nixpkgs.follows = "nixpkgs";
  };

  outputs = { self, nixpkgs, ... }@inputs: inputs.utils.lib.eachSystem [
    "x86_64-linux" "i686-linux" "aarch64-linux" "x86_64-darwin" "aarch64-darwin"
  ] (system: let pkgs = import nixpkgs {
                   inherit system;
                 };
             in {
               devShell = pkgs.mkShell rec {
                 name = "screenshot_mwe";

                 packages = with pkgs; [
                   # Development Tools
                   cmake
                   cmakeCurses
                   qt6.qttools
                   qt6.wrapQtAppsHook

                   # Dependencies
                   qt6.qtsvg
                   qt6.qtbase
                 ];
               };
               defaultPackage = pkgs.callPackage ./default.nix {
                qtbase = pkgs.qt6.qtbase;
                qttools = pkgs.qt6.qttools;
                qtsvg = pkgs.qt6.qtsvg;
                wrapQtAppsHook = pkgs.qt6.wrapQtAppsHook;
                };
             });
}
