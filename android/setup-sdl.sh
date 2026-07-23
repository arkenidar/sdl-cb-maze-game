#!/bin/sh
# Download the pinned SDL2 release and place the pieces the Android APK build
# needs but that are not tracked in git (see android/.gitignore):
#   app/jni/SDL/                      - SDL2 C source, built via add_subdirectory
#   app/src/main/java/org/libsdl/app/ - the Java glue (SDLActivity etc.)
# Sourcing both from the same tarball keeps the Java glue and the native
# library at matching versions. Idempotent: safe to re-run; re-run after
# changing SDL_VERSION below to upgrade.
set -eu
cd "$(dirname "$0")"

SDL_VERSION=2.30.11
TARBALL="SDL2-$SDL_VERSION.tar.gz"
URL="https://github.com/libsdl-org/SDL/releases/download/release-$SDL_VERSION/$TARBALL"

if [ ! -f "$TARBALL" ]; then
    echo "Downloading $URL"
    curl -fL -o "$TARBALL" "$URL"
fi

rm -rf "SDL2-$SDL_VERSION" app/jni/SDL app/src/main/java/org/libsdl
tar xzf "$TARBALL"

mv "SDL2-$SDL_VERSION" app/jni/SDL
mkdir -p app/src/main/java/org/libsdl/app
cp app/jni/SDL/android-project/app/src/main/java/org/libsdl/app/*.java \
   app/src/main/java/org/libsdl/app/

echo "SDL $SDL_VERSION ready. Build with: ./gradlew assembleDebug"
