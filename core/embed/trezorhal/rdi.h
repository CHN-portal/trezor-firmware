/*
 * This file is part of the Trezor project, https://trezor.io/
 *
 * Copyright (c) SatoshiLabs
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef __TREZORHAL_RDI_H__
#define __TREZORHAL_RDI_H__

#include "chacha20poly1305/ecrypt-sync.h"
#include "memzero.h"

#define CHACHA_DRBG_KEY_LENGTH 16
#define CHACHA_DRBG_IV_LENGTH 8
#define CHACHA_DRBG_SEED_LENGTH (CHACHA_DRBG_KEY_LENGTH + CHACHA_DRBG_IV_LENGTH)

typedef struct _CHACHA_DRBG_CTX {
  ECRYPT_ctx chacha_ctx;
  uint32_t reseed_counter;
} CHACHA_DRBG_CTX;

void chacha_drbg_init(CHACHA_DRBG_CTX *ctx, const uint8_t entropy[CHACHA_DRBG_SEED_LENGTH]);
void chacha_drbg_reseed(CHACHA_DRBG_CTX *ctx, const uint8_t entropy[CHACHA_DRBG_SEED_LENGTH]);
void chacha_drbg_generate(CHACHA_DRBG_CTX *ctx, uint8_t *output, uint8_t output_length);

void rdi_handler(void);
void rdi_start(void);
void rdi_stop(void);
void rdi_regenerate_session_delay(void);
#endif
