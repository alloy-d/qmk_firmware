#pragma once

#ifdef ORTHO_4X12
#define LAYOUT_ortho( \
    kx0, kx1, kx2, kx3, kx4, kx5, kx6, kx7, kx8, kx9, kxa, kxb, \
    k00, k01, k02, k03, k04, k05, k06, k07, k08, k09, k0a, k0b, \
    k10, k11, k12, k13, k14, k15, k16, k17, k18, k19, k1a, k1b, \
    k20, k21, k22, k23, k24, k25, k26, k27, k28, k29, k2a, k2b, \
    k30, k31, k32, k33, k34, k35, k36, k37, k38, k39, k3a, k3b  \
) \
LAYOUT_ortho_4x12( \
    k00, k01, k02, k03, k04, k05, k06, k07, k08, k09, k0a, k0b, \
    k10, k11, k12, k13, k14, k15, k16, k17, k18, k19, k1a, k1b, \
    k20, k21, k22, k23, k24, k25, k26, k27, k28, k29, k2a, k2b, \
    k30, k31, k32, k33, k34, k35, k36, k37, k38, k39, k3a, k3b  \
)

#elif defined(ORTHO_HELIX_4ROW)
// FIXME: make this less hacky.
#define LAYOUT_ortho( \
    kx0, kx1, kx2, kx3, kx4, kx5, kx6, kx7, kx8, kx9, kxa, kxb, \
    k00, k01, k02, k03, k04, k05, k06, k07, k08, k09, k0a, k0b, \
    k10, k11, k12, k13, k14, k15, k16, k17, k18, k19, k1a, k1b, \
    k20, k21, k22, k23, k24, k25, k26, k27, k28, k29, k2a, k2b, \
    k30, k31, k32, k33, k34, k35, k36, k37, k38, k39, k3a, k3b  \
) \
LAYOUT( \
    k00, k01, k02, k03, k04, k05, k06, k07, k08, k09, k0a, k0b, \
    k10, k11, k12, k13, k14, k15, k16, k17, k18, k19, k1a, k1b, \
    k20, k21, k22, k23, k24, k25, k26, k27, k28, k29, k2a, k2b, \
    k30, k31, k32, k33, k34, k35, KC_SYRQ, KC_INS, k36, k37, k38, k39, k3a, k3b  \
)

#elif defined(ORTHO_5X12)
#define LAYOUT_ortho( \
    k00, k01, k02, k03, k04, k05, k06, k07, k08, k09, k0a, k0b, \
    k10, k11, k12, k13, k14, k15, k16, k17, k18, k19, k1a, k1b, \
    k20, k21, k22, k23, k24, k25, k26, k27, k28, k29, k2a, k2b, \
    k30, k31, k32, k33, k34, k35, k36, k37, k38, k39, k3a, k3b, \
    k40, k41, k42, k43, k44, k45, k46, k47, k48, k49, k4a, k4b  \
) \
LAYOUT_ortho_5x12( \
    k00, k01, k02, k03, k04, k05, k06, k07, k08, k09, k0a, k0b, \
    k10, k11, k12, k13, k14, k15, k16, k17, k18, k19, k1a, k1b, \
    k20, k21, k22, k23, k24, k25, k26, k27, k28, k29, k2a, k2b, \
    k30, k31, k32, k33, k34, k35, k36, k37, k38, k39, k3a, k3b, \
    k40, k41, k42, k43, k44, k45, k46, k47, k48, k49, k4a, k4b  \
)

#elif defined(ORTHO_5X14)
#define LAYOUT_ortho( \
    k00, k01, k02, k03, k04, k05, k08, k09, k0a, k0b, k0c, k0d, \
    k10, k11, k12, k13, k14, k15, k18, k19, k1a, k1b, k1c, k1d, \
    k20, k21, k22, k23, k24, k25, k28, k29, k2a, k2b, k2c, k2d, \
    k30, k31, k32, k33, k34, k35, k38, k39, k3a, k3b, k3c, k3d, \
    k40, k41, k42, k43, k44, k45, k48, k49, k4a, k4b, k4c, k4d  \
) \
LAYOUT_ortho_5x14( \
    k00, k01, k02, k03, k04, k05, KC_MINS, KC_EQL, k08, k09, k0a, k0b, k0c, k0d, \
    k10, k11, k12, k13, k14, k15, KC_LBRC, KC_RBRC, k18, k19, k1a, k1b, k1c, k1d, \
    k20, k21, k22, k23, k24, k25, KC_HOME, KC_PGUP, k28, k29, k2a, k2b, k2c, k2d, \
    k30, k31, k32, k33, k34, k35, KC_END, KC_PGDN, k38, k39, k3a, k3b, k3c, k3d, \
    k40, k41, k42, k43, k44, k45, KC_SPC, KC_SPC, k48, k49, k4a, k4b, k4c, k4d  \
)
#endif
