{ stdenv
, lib
, qt6Packages
, wrapQtAppsHook
, cmake
, qtbase
, qttools
, qtsvg 
}:

with qt6Packages;

stdenv.mkDerivation rec {
  pname = "screenshot_mwe";
  version = "0.1.0";
  
  src = ./.;

  nativeBuildInputs = [ 
    cmake 
    qttools
    qtsvg
    wrapQtAppsHook
    ];
  buildInputs = [ qtbase ];
  cmakeFlags = [
  ];

  meta = with lib; {
    homepage = "";
    description = ''
    '';
    licencse = licenses.gpl3Plus;
    platforms = with platforms; linux ++ darwin;
  };
}