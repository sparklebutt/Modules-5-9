#!/bin/bash

BASE_NAME=$1
#OLD_CLASS=$2
NEW_CLASS=$2

# CREATE COPIES
cp "${BASE_NAME}.hpp" "${NEW_CLASS}.hpp"
cp "${BASE_NAME}.cpp" "${NEW_CLASS}.cpp"

# replace class names in new file
sed -i "s/${BASE_NAME}/${NEW_CLASS}/g" "${NEW_CLASS}.hpp"
sed -i "s/${BASE_NAME}/${NEW_CLASS}/g" "${NEW_CLASS}.cpp"
