/*-------------------------------------------------------------------------
 *
 * pg_shdescription.h
 *	  definition of the system "shared description" relation
 *	  (pg_shdescription)
 *
 * NOTE: an object is identified by the OID of the row that primarily
 * defines the object, plus the OID of the table that that row appears in.
 * For example, a database is identified by the OID of its pg_database row
 * plus the pg_class OID of table pg_database.	This allows unique
 * identification of objects without assuming that OIDs are unique
 * across tables.
 *
 *
 * Portions Copyright (c) 1996-2008, PostgreSQL Global Development Group
 * Portions Copyright (c) 1994, Regents of the University of California
 *
 * $PostgreSQL: pgsql/src/include/catalog/pg_shdescription.h,v 1.3 2006/10/04 00:30:08 momjian Exp $
 *
 * NOTES
 *		the genbki.sh script reads this file and generates .bki
 *		information from the DATA() statements.
 *
 *		XXX do NOT break up DATA() statements into multiple lines!
 *			the scripts are not as smart as you might think...
 *
 *-------------------------------------------------------------------------
 */
#ifndef PG_SHDESCRIPTION_H
#define PG_SHDESCRIPTION_H

#include "catalog/genbki.h"

/* TIDYCAT_BEGINFAKEDEF

   CREATE TABLE pg_shdescription
   with (camelcase=SharedDescription, shared=true, oid=false, relid=2396, toast_oid=2846, toast_index=2847, content=MASTER_ONLY)
   (
   objoid       oid, 
   classoid     oid, 
   description  text
   );

   create unique index on pg_shdescription(objoid, classoid) with (indexid=2397, CamelCase=SharedDescriptionObj);

   alter table pg_shdescription add fk classoid on pg_class(oid);

   TIDYCAT_ENDFAKEDEF
*/

/* ----------------
 *		pg_shdescription definition.	cpp turns this into
 *		typedef struct FormData_pg_shdescription
 * ----------------
 */
#define SharedDescriptionRelationId  2396

CATALOG(pg_shdescription,2396) BKI_SHARED_RELATION BKI_WITHOUT_OIDS
{
	Oid			objoid;			/* OID of object itself */
	Oid			classoid;		/* OID of table containing object */
	text		description;	/* description of object */
} FormData_pg_shdescription;

/* ----------------
 *		Form_pg_shdescription corresponds to a pointer to a tuple with
 *		the format of pg_shdescription relation.
 * ----------------
 */
typedef FormData_pg_shdescription *Form_pg_shdescription;

/* ----------------
 *		compiler constants for pg_shdescription
 * ----------------
 */
#define Natts_pg_shdescription			3
#define Anum_pg_shdescription_objoid		1
#define Anum_pg_shdescription_classoid	2
#define Anum_pg_shdescription_description 3

/* ----------------
 *		initial contents of pg_shdescription
 * ----------------
 */

/*
 *	Because the contents of this table are taken from the other *.h files,
 *	there is no initialization here.  The initial contents are extracted
 *	by genbki.sh and loaded during initdb.
 */

#endif   /* PG_SHDESCRIPTION_H */
