ORIGIN=origin
TARGET=target
TRANS=../sfm_conv

# original makefile
default: ${ORIGIN}/a

${ORIGIN}/a: ${ORIGIN}/a.cpp ${ORIGIN}/a.h
	clang++ ${ORIGIN}/a.cpp -o $@

# sfm makefile
sfm: ${TARGET}/a
	@echo "finished"

${TARGET}/a: ${TARGET}/a.cpp ${TARGET}/a.h
	clang++ ${TARGET}/a.cpp -o $@

${TARGET}/a.cpp: ${TARGET}/a.bc ${ORIGIN}/a.cpp
	$(TRANS) $^ > $@
# 2>/dev/null

${TARGET}/a.bc: ${ORIGIN}/a.cpp
	clang++ -emit-llvm -c -g $^ -o $@
	clang++ -emit-llvm -S -g $^ -o $@.ll

# cleaning
.PHONY: clean
clean:
	rm -f ${ORIGIN}/*.o ${ORIGIN}/a
	rm -f ${TARGET}/*.o ${TARGET}/*.ll ${TARGET}/*.bc ${TARGET}/a
	rm ${TARGET}/a.cpp

