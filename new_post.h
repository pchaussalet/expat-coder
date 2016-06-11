#!/bin/sh
TITLE=$1
pip install -q --user awesome-slugify
SLUG=$(python -c 'from slugify import slugify; import sys; print(slugify(sys.argv[1], to_lower=True))' "${TITLE}")

NEW_FILE=$(hugo new "post/${TITLE}" | sed 's/ created$//')
echo $NEW_FILE
mv "${NEW_FILE}" "$(dirname ${NEW_FILE})/$SLUG.md"
