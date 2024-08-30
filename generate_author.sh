#!/bin/sh

# The following script generates the author designation based on Git history

git shortlog -se \
	| perl -spe 's/^\s+\d+\s+//' \
	| sed -e '/^CommitSyncScript.*$/d' \
	> AUTHOR
