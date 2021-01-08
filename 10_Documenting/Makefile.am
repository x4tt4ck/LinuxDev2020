bin_PROGRAMS=numg
pkgdata_DATA=ru/LC_MESSAGES/numg.mo

@DX_RULES@

ru/LC_MESSAGES/numg.mo: runumg.po
		mkdir -p `dirname $@`
		msgfmt $< -o $@

runumg.po:	num.pot
		msgmerge -U $@ $<

num.pot:	numg.pot numg.c
		xgettext -k_ -c numg.c -o numg.new.pot
		cp numg.pot num.pot
		msgmerge -U num.pot numg.new.pot

gitclean:	maintainer-clean
	git clean -fd
