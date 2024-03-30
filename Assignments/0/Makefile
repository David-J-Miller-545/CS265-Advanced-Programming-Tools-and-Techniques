
PY = python3
PYFLAGS =
PAGER = less


.PHONY : hello view run clean

hello :
	-echo -e "\nHello there, $$USER\n"

view : foo
	-$(PAGER) foo

run : foo
	$(PY) foo

clean :
	\rm -r __pycache__ 

