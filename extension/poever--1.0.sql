-- complain if script is sourced in psql, rather than via CREATE EXTENSION
\echo Use "CREATE EXTENSION poever" to load this file. \quit

CREATE FUNCTION cell_root_refs(bytea)
    RETURNS integer
AS 'MODULE_PATHNAME'
    LANGUAGE C;

CREATE FUNCTION cell_root_hash(bytea)
    RETURNS text
AS 'MODULE_PATHNAME'
    LANGUAGE C;
