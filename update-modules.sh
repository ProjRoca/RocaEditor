#!/bin/bash

declare -A modules
modules=(
    ["lib/QRockyStyle"]="https://github.com/ProjRoca/QRockyStyle"
)

set -e
lastwd="$PWD"
for module in "${!modules[@]}"
do
    echo "Updating module '$module'"
    if [ -e "$module/.git" ]
    then
        cd "$module"
        git fetch --all
        git reset --hard origin
        cd "$lastwd"
    else
        mkdir -p "$(dirname "$module")"
        git clone --recursive --depth=1 -- "${modules[$module]}" "$module"
    fi
    if [ -e "$module/update-modules.sh" ]
    then
        cd "$module"
        bash update-modules.sh
    fi
    cd "$lastwd"
done
