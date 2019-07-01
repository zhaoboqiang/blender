#ifndef __LANPR_ACCESS_H__
#define __LANPR_ACCESS_H__

#include "DNA_gpencil_types.h"
#include "DNA_gpencil_modifier_types.h"

#include "DEG_depsgraph.h"

#include "BKE_gpencil.h"

typedef struct LANPR_RenderLineChain LANPR_RenderLineChain;

void lanpr_generate_gpencil_from_chain(Depsgraph *depsgraph,
                                       struct Object *ob,
                                       bGPDlayer *gpl,
                                       bGPDframe *gpf,
                                       int qi_begin,
                                       int qi_end,
                                       int material_nr,
                                       struct Collection *col,
                                       int types);

void lanpr_update_data_for_external(Depsgraph *depsgraph);

int lanpr_count_chain(LANPR_RenderLineChain *rlc);

void lanpr_chain_clear_picked_flag(struct LANPR_RenderBuffer *rb);

int lanpr_compute_feature_lines_internal(Depsgraph *depsgraph);

void lanpr_destroy_render_data(struct LANPR_RenderBuffer *rb);

bool lanpr_dpix_shader_error();

bool lanpr_disable_edge_splits(struct Scene *s);

void lanpr_copy_data(struct Scene *from, struct Scene *to);

void lanpr_free_everything(struct Scene *s);

#endif
