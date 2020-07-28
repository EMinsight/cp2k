/*****************************************************************************
 *  CP2K: A general program to perform molecular dynamics simulations        *
 *  Copyright (C) 2000 - 2020  CP2K developers group                         *
 *****************************************************************************/

#ifndef GRID_COLLOCATE_REPLAY_H
#define GRID_COLLOCATE_REPLAY_H

#include <stdbool.h>


//******************************************************************************
// \brief Writes the given arguments into a .task file.
// \author Ole Schuett
//******************************************************************************
void grid_collocate_record(const bool orthorhombic,
                           const int border_mask,
                           const int func,
                           const int la_max,
                           const int la_min,
                           const int lb_max,
                           const int lb_min,
                           const double zeta,
                           const double zetb,
                           const double rscale,
                           const double dh[3][3],
                           const double dh_inv[3][3],
                           const double ra[3],
                           const double rab[3],
                           const int npts_global[3],
                           const int npts_local[3],
                           const int shift_local[3],
                           const int border_width[3],
                           const double radius,
                           const int o1,
                           const int o2,
                           const int n1,
                           const int n2,
                           const double pab[n2][n1],
                           const double* grid);


//******************************************************************************
// \brief Reads a .task file, collocates it, and compares results to reference.
//
// \param filename          Name of the task file.
// \param cycles            Number of times the task should be collocated.
// \param batch             When false grid_collocate_pgf_product_cpu is called.
//                          When true grid_collocate_task_list is called.
// \param cycles_per_block  Number of cycles per matrix block decontraction.
// \returns                 The maximum difference for an individual grid point.
//
// \author Ole Schuett
//******************************************************************************
double grid_collocate_replay(const char* filename,
                             const int cycles,
                             const bool batch,
                             const int cycles_per_block);

#endif

//EOF
