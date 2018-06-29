grep -i "\(^\|\s\)nicolas\sbauer" $1 | grep -i "\(^\|\s\)bauer" | rev | cut -d $'\t' -f2 | rev
