// Copyright (c) 2012-2016, The CryptoNote developers, The Bytecoin developers, The Karbowanec developers
// Copyright (c) 2017, The Niobio developers
//
// This file is part of Bytecoin.
//
// Bytecoin is free software: you can redistribute it and/or modify
// it under the terms of the GNU Lesser General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
//
// Bytecoin is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU Lesser General Public License for more details.
//
// You should have received a copy of the GNU Lesser General Public License
// along with Bytecoin.  If not, see <http://www.gnu.org/licenses/>.

#pragma once

#include <cstdint>

namespace CryptoNote {
namespace parameters {

const uint64_t DIFFICULTY_TARGET                             = 240; // seconds
const uint64_t CRYPTONOTE_MAX_BLOCK_NUMBER                   = 500000000;
const size_t   CRYPTONOTE_MAX_BLOCK_BLOB_SIZE                = 500000000;
const size_t   CRYPTONOTE_MAX_TX_SIZE                        = 1000000000;
const uint64_t CRYPTONOTE_PUBLIC_ADDRESS_BASE58_PREFIX       = 126; // addresses start with "N"
const size_t   CRYPTONOTE_MINED_MONEY_UNLOCK_WINDOW          = 10;
const size_t   TESTNET_CRYPTONOTE_MINED_MONEY_UNLOCK_WINDOW  = 0;
const uint64_t CRYPTONOTE_BLOCK_FUTURE_TIME_LIMIT            = 60 * 60 * 2;
const uint64_t CRYPTONOTE_BLOCK_FUTURE_TIME_LIMIT_V4         = DIFFICULTY_TARGET * 7;

const size_t   BLOCKCHAIN_TIMESTAMP_CHECK_WINDOW             = 60;
const size_t   BLOCKCHAIN_TIMESTAMP_CHECK_WINDOW_V5          = 11;

// MONEY_SUPPLY - total number coins to be generated
const uint64_t MONEY_SUPPLY                                  = UINT64_C(33600000000000000);
const uint64_t TAIL_EMISSION_REWARD                          = 0; //UINT64_C(1000000000000);
const size_t CRYPTONOTE_COIN_VERSION                         = 1;
const unsigned EMISSION_SPEED_FACTOR                         = 18;
const unsigned EMISSION_SPEED_FACTOR_V5                      = 20;
const uint64_t EMISSION_REDUCTOR_V6                          = UINT64_C(2147483648);
static_assert(EMISSION_SPEED_FACTOR <= 8 * sizeof(uint64_t), "Bad EMISSION_SPEED_FACTOR");
static_assert(EMISSION_SPEED_FACTOR_V5 <= 8 * sizeof(uint64_t), "Bad EMISSION_SPEED_FACTOR");
const size_t   CRYPTONOTE_REWARD_BLOCKS_WINDOW               = 100;
const size_t   CRYPTONOTE_BLOCK_GRANTED_FULL_REWARD_ZONE     = 1000000; //size of block (bytes) after which reward for block calculated using block size
const size_t   CRYPTONOTE_BLOCK_GRANTED_FULL_REWARD_ZONE_V2  = 1000000;
const size_t   CRYPTONOTE_BLOCK_GRANTED_FULL_REWARD_ZONE_V1  = 100000;
const size_t   CRYPTONOTE_BLOCK_GRANTED_FULL_REWARD_ZONE_CURRENT = CRYPTONOTE_BLOCK_GRANTED_FULL_REWARD_ZONE;
const size_t   CRYPTONOTE_COINBASE_BLOB_RESERVED_SIZE        = 600;
const size_t   CRYPTONOTE_DISPLAY_DECIMAL_POINT              = 8;
const uint64_t MINIMUM_FEE                                   = UINT64_C(1000);
const uint64_t DEFAULT_DUST_THRESHOLD                        = UINT64_C(1000);

const uint64_t EXPECTED_NUMBER_OF_BLOCKS_PER_DAY             = 24 * 60 * 60 / DIFFICULTY_TARGET;
const size_t   DIFFICULTY_WINDOW                             = 36; //EXPECTED_NUMBER_OF_BLOCKS_PER_DAY; // blocks
const size_t   DIFFICULTY_WINDOW_V2                          = 36; //17; // blocks
const size_t   DIFFICULTY_WINDOW_V4                          = 61; // blocks
const size_t   DIFFICULTY_CUT                                = 0; // timestamps to cut after sorting
const size_t   DIFFICULTY_LAG                                = 0; //15;  // !!!
static_assert(2 * DIFFICULTY_CUT <= DIFFICULTY_WINDOW - 2, "Bad DIFFICULTY_WINDOW or DIFFICULTY_CUT");

const size_t   MAX_BLOCK_SIZE_INITIAL                        = 1000000;
const uint64_t MAX_BLOCK_SIZE_GROWTH_SPEED_NUMERATOR         = 100 * 1024;
const uint64_t MAX_BLOCK_SIZE_GROWTH_SPEED_DENOMINATOR       = 365 * 24 * 60 * 60 / DIFFICULTY_TARGET;

const uint64_t CRYPTONOTE_LOCKED_TX_ALLOWED_DELTA_BLOCKS     = 1;
const uint64_t CRYPTONOTE_LOCKED_TX_ALLOWED_DELTA_SECONDS    = DIFFICULTY_TARGET * CRYPTONOTE_LOCKED_TX_ALLOWED_DELTA_BLOCKS;

const uint64_t CRYPTONOTE_MEMPOOL_TX_LIVETIME                = 60 * 60 * 24 * 2;     //seconds
const uint64_t CRYPTONOTE_MEMPOOL_TX_FROM_ALT_BLOCK_LIVETIME = 60 * 60 * 24 * 1; // 7; //seconds
const uint64_t CRYPTONOTE_NUMBER_OF_PERIODS_TO_FORGET_TX_DELETED_FROM_POOL = 7; // 7;  // CRYPTONOTE_NUMBER_OF_PERIODS_TO_FORGET_TX_DELETED_FROM_POOL * CRYPTONOTE_MEMPOOL_TX_LIVETIME = time to forget tx

const size_t   FUSION_TX_MAX_SIZE                            = CRYPTONOTE_BLOCK_GRANTED_FULL_REWARD_ZONE_CURRENT * 30 / 100;
//const size_t   FUSION_TX_MIN_INPUT_COUNT                     = 12;
const size_t   FUSION_TX_MIN_INPUT_COUNT                     = 4;
const size_t   FUSION_TX_MIN_IN_OUT_COUNT_RATIO              = 2;

const uint32_t UPGRADE_HEIGHT_V2                             = 1;
const uint32_t UPGRADE_HEIGHT_V3                             = 30;
const uint32_t UPGRADE_HEIGHT_V4                             = 73731;
const uint32_t UPGRADE_HEIGHT_V5                             = 92999;
const uint32_t UPGRADE_HEIGHT_V6                             = 153559;

const unsigned UPGRADE_VOTING_THRESHOLD                      = 90;   // percent
const uint32_t UPGRADE_VOTING_WINDOW                         = EXPECTED_NUMBER_OF_BLOCKS_PER_DAY;  // blocks
const uint32_t UPGRADE_WINDOW                                = EXPECTED_NUMBER_OF_BLOCKS_PER_DAY;  // blocks
static_assert(0 < UPGRADE_VOTING_THRESHOLD && UPGRADE_VOTING_THRESHOLD <= 100, "Bad UPGRADE_VOTING_THRESHOLD");
static_assert(UPGRADE_VOTING_WINDOW > 1, "Bad UPGRADE_VOTING_WINDOW");

const char     CRYPTONOTE_BLOCKS_FILENAME[]                  = "blocks.dat";
const char     CRYPTONOTE_BLOCKINDEXES_FILENAME[]            = "blockindexes.dat";
const char     CRYPTONOTE_BLOCKSCACHE_FILENAME[]             = "blockscache.dat";
const char     CRYPTONOTE_POOLDATA_FILENAME[]                = "poolstate.bin";
const char     P2P_NET_DATA_FILENAME[]                       = "p2pstate.bin";
const char     CRYPTONOTE_BLOCKCHAIN_INDICES_FILENAME[]      = "blockchainindices.dat";
const char     MINER_CONFIG_FILE_NAME[]                      = "miner_conf.json";
const char     TESTNET_FILENAME_PREFIX[]                     = "testnet_";
} // parameters

const char     CRYPTONOTE_NAME[]                             = "niobio";
const char     GENESIS_COINBASE_TX_HEX[]                     = "010a01ff00019dd085bedd03029b2e4c0281c0b02e7c53291a94d1d0cbff8883f8024f5142ee494ffbbd0880712101ad57d730d6e2419095871c3b5882daa96e0d30af050f7c97bfbe2433593224ee";

const uint8_t  CURRENT_TRANSACTION_VERSION                   =  1;
const uint8_t  BLOCK_MAJOR_VERSION_1                         =  1;
const uint8_t  BLOCK_MAJOR_VERSION_2                         =  2;
const uint8_t  BLOCK_MAJOR_VERSION_3                         =  3;
const uint8_t  BLOCK_MAJOR_VERSION_4                         =  4;
const uint8_t  BLOCK_MAJOR_VERSION_5                         =  5;
const uint8_t  BLOCK_MAJOR_VERSION_6                         =  6;
const uint8_t  BLOCK_MINOR_VERSION_0                         =  0;
const uint8_t  BLOCK_MINOR_VERSION_1                         =  1;

const size_t   BLOCKS_IDS_SYNCHRONIZING_DEFAULT_COUNT        =  64;  //by default, blocks ids count in synchronizing
const size_t   BLOCKS_SYNCHRONIZING_DEFAULT_COUNT            =  64;    //by default, blocks count in blocks downloading
const size_t   COMMAND_RPC_GET_BLOCKS_FAST_MAX_COUNT         =  64;

const int      P2P_DEFAULT_PORT                              =  8313;
const int      RPC_DEFAULT_PORT                              =  8314;

const size_t   P2P_LOCAL_WHITE_PEERLIST_LIMIT                =  1000;
const size_t   P2P_LOCAL_GRAY_PEERLIST_LIMIT                 =  500;

const size_t   P2P_CONNECTION_MAX_WRITE_BUFFER_SIZE          = 64 * 1024 * 1024; // 64 MB
const uint32_t P2P_DEFAULT_CONNECTIONS_COUNT                 = 10;
const size_t   P2P_DEFAULT_WHITELIST_CONNECTIONS_PERCENT     = 70;
const uint32_t P2P_DEFAULT_HANDSHAKE_INTERVAL                = 60;            // seconds
const uint32_t P2P_DEFAULT_PACKET_MAX_SIZE                   = 50000000;      // 50000000 bytes maximum packet size
const uint32_t P2P_DEFAULT_PEERS_IN_HANDSHAKE                = 250;
const uint32_t P2P_DEFAULT_CONNECTION_TIMEOUT                = 5000;          // 5 seconds
const uint32_t P2P_DEFAULT_PING_CONNECTION_TIMEOUT           = 2000;          // 2 seconds
const uint64_t P2P_DEFAULT_INVOKE_TIMEOUT                    = 60 * 2 * 1000; // 2 minutes
const size_t   P2P_DEFAULT_HANDSHAKE_INVOKE_TIMEOUT          = 5000;          // 5 seconds
const char     P2P_STAT_TRUSTED_PUB_KEY[]                    = "";

const char* const SEED_NODES[] = {
	"198.245.50.69:8313",
	"173.249.38.45:8313",
	"80.241.215.133:8313",
	"45.55.141.227:8313"
};

struct CheckpointData {
  uint32_t height;
  const char* blockId;
};

const std::initializer_list<CheckpointData> CHECKPOINTS = {
	{ 1,     "62b3674f55adf428b586c9c45ec0f0c57660c61ac28c3f3bc087f8fccf246230" },
	{ 14000, "acd4ffd637dedf06237bdc4ed6175bdcac9e01f907846a7d6d910a15826c4916" },
	{ 19111, "80a25bf8b24f6b286d81d3fb9f65a3dd55c9fe1d508b3d463fa1c0512e45af6f" },
	{ 19112, "7a0a41f6ccbf72b47a21841b8e876f29877bb57aa15d7adda27c757e77fc7021" },
	{ 24758, "ef7b7c3803df58e06b21dde88c252569f118cda2fafeae9b56c6061e7c4c18eb" },
	{ 24759, "c244f99cbcdae7eadbe19e72d17746cdb36b3fb5a446e2cd464a1bf8e4264f3c" },
	{ 27100, "3fef469241c26535b6b7dd5482e9456ee637aac6337c17b51cafca8b6848603d" },
	{ 27990, "0adbe06af69b87ed756c81c1581264732304eb20b4cd1bf56d7c645b9bf9d8d7" },
	{ 29100, "bf7880e1d3fe46f1dde7351194204820ee9b5045496b6a14d10bbfe704519b8b" },
	{ 30200, "22961a5cdebe8120ecb6cb74f03b043bf24aca54658e7d39d067bb0477fd5029" },
	{ 32186, "599e39f9fd2a43550964c5d16c80dfcf354d559bb1110379ccff177bbf90814a" },
	{ 32187, "0da9cbff2e14f4f666b4f50fe75b1ff29dfabed1f46b848e21c1c54c3684edae" },
	{ 32352, "49d308cac8a7d48dee827349040bc1762c201f968f1a1d71b61fe43e448a817e" },
	{ 32353, "5fafb60141d28d6145387c869d3911de0ab34a559b96614fae328f73d45f607f" },
	{ 32369, "38705adb21b1eaa6c09225b534d55ab74e7a30f198bafeeedd00ea0de4d517a3" },
	{ 32370, "055aff89d01f240120ff6e328ae40304bb0d1c1b3a4db857125fe6e2000572bf" },
	{ 32524, "daaa655ca784f2ed0544f2f555ccad6ac030333ef2fb8ca8739de8d812b404ae" },
	{ 32525, "ff9d83adabd88968b25d00fe1c80d53b172424b62c78b0597b4a4cebc0f121e7" },
	{ 32855, "a837dcd54b057f4e8abace74f916f8fc89fc77f2ce4e0efff09ffb87baf65ab9" },
	{ 33000, "e154e8df0facc073503e013e7ed7f2413f05cd46c9769d468767b3aed49c839f" },
	{ 33375, "8ce543f8449e6e8008bc9afb05a6e4c6ce451c50bd1c84da2db6c4cdbc6e2d85" },
	{ 33773, "1aed0bcb07420207154c97431ab6607edb9898587098991049578e38f173f929" },
	{ 34000, "ec556ea2bd8b50ad9e83c7f7fa79fa84bbcf6d8288ccf6e2c4b96af644a8f581" },
	{ 34315, "815014644195d8959efd93c506337bbbb2d2615141f21e4dd93dcff796acfc20" },
	{ 34396, "6bd1eb16ee0c815922c22e1f352b6387112dacfec36306880895dbba8deeec30" },
	{ 34760, "f0e0fbc92f69e3dcadd0ca31c7c4eda021f8c50099428a119829ecb9fcf3e29b" },
	{ 34852, "6cb8a76b41eac291cd7cf74482b3309ecb1623825b592b1267a104caf7d96c8d" },
	{ 35000, "7eac17f1c048a141f60ee39332a4c0ee873a09eb53e35d6f7172ce78bfb56e8c" },
	{ 35591, "2dfbc50e1793c1bb82d4bfffaed25d70ae2ce30b871c70d1625d1e631bfbc71b" },
	{ 35689, "62ba9bd03dfe51e3a1b334ff88d28407452e287b71c91f712ac5886acc94be40" },
	{ 35900, "6538ca031f1868672e0cadc4f3338479106bceb0972e146177b0b9dee00608d1" },
	{ 36000, "1372ee6202eff5dd19bb12b24d66d18d6dd15a5e9598ef987f2372158aa7bc5c" },
	{ 36500, "d4e76dd60300cfeebe7a0b01e59b387949aa19855bea686cfda8590729265966" },
	{ 37000, "c826741a34f2fd9a5b47bc09123539465c9815fc1590e6fae7fc7534b90a6716" },
	{ 37500, "4e134c3094f6bcb9d3dd724ad7971a15a2b28bd36a7d3f71734fefa84246b087" },
	{ 38000, "8af3e62e1191c372b96ff3f30f1115d55ca45e713596315feec22a3037471ef7" },
	{ 38500, "241638d18259d85b96e24983e20520ab169a5bddad4b55882c9b28d65ce468aa" },
	{ 39000, "a274637628b8eab46e749a90e40a8530694c21305b8d26c75f0c27b214244427" },
	{ 39206, "fdd7c53147a084b84418a59225a02b96b1b8cbe8e567a5a5ff9ccf29e0f8fbec" },
	{ 39318, "497012a6d84bf2542747d738b1037dadb7b1e7885091e8860acfd3fabd196551" },
	{ 39319, "2ff445581f4aadf90ef8ebfe5b9ae1227a6c126290152c93afd352338334b23d" },
	{ 39326, "64f45a501a206d91ad0df84e91d422e54eaa655a7159a87ef3034e487f9f3ea4" },
	{ 39329, "3fee7fe3ec965ed629ff01af8eebd89c1ef09a221e0a52fe53b32ccd75a4ce04" },
	{ 39359, "efe94dda8fac610894fffc6a7135bd1869bc827d286fcaaae5e13b94a876bf8a" },
	{ 39421, "33ed8b5a1e3b925de9b8512e81e2fa57e129b91028c20e43e3bb16ef399d016b" },
	{ 39500, "035f9be0f7d2cf8fffc55a698e90be74d8885321f4c43468cfdd3aa013e5d094" },
	{ 41100, "f917db589f0bb85d7538528672e8e5166e222bf3e7086d39ec7999ce7a361915" },
	{ 41727, "4581bcd69a4924b0cd7c6c9f8e65817feaba3ae3ec984a4b1ede2c450b9eb31e" },
	{ 46696, "7d0d9048be57c80d2c44fe67555b65d93449e088c0773ae630b6165f87562057" },
	{ 47329, "dbe612e290285c5c5a80f496692be4a6e49c09abee1f50455563ad0a256e748b" },
	{ 47330, "924feb71a2c589718e8c8a922d9cf5e3ad3163441e4c975bbf41e413481342c2" },
	{ 55796, "57669ca842c749dea8d50eded31f3b7082b9e5482b73fb9ce60aa1d431e49dea" },
	{ 66568, "d3d2f05745ce8af6e71b190782e560362cbc62571ffce7fb7c4b5bd848e88ea1" },
	{ 71714, "71af9b2599f0a44cdaa8be0dba5d78f4c23dbb3730d69ee217e6a8f0649f9592" },
	{ 76072, "85313bc7fc25455f71ceab7660470b4bb6d22d6c72551f80a55308616d7ec19a" },
	{ 81895, "759d10ef6fcdd6f0b91ca59369d5c4cb0543102d054c421210bd57a4cbdae5dd" },
	{ 90132, "6012c9bf6e8970f49de3736a4e952a465c61c67770d3c44e83509c9b2375ccc4" },
	{ 94584, "cdc4a440b8a9e3bc4b1e665421d22d8c4895e3df92dcad248492a346aad63c28" },
	{ 153559, "f18fd86dfd2a2d2d5bc8b4ae33994921b8afed5fa75faa7142d78cb4e00241f7" },
	{ 153560, "d4199fa557bbb0e2d29dc306a65c731f210fe4cf47293230828ccba96b13929d" },
	{ 153790, "74a87612eefb8a029e26e9ce6e22524a88b9d4ad9964524e025135d1d8a650af" }
};

} // CryptoNote

#define ALLOW_DEBUG_COMMANDS
