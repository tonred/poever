MODULES = poever

EXTENSION = poever
DATA = poever--1.0.sql
PGFILEDESC = "poever - everscale-types extension for postgresql"

REGRESS = poever
PG_CONFIG = pg_config
PGXS := $(shell $(PG_CONFIG) --pgxs)
EXTRA_CLEAN = libpoever.a
PG_LDFLAGS = -lpoever -L/Users/pavelkhachatrian/PycharmProjects/poever/extension
include $(PGXS)
