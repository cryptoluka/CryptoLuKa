// Copyright (c) 2018, CryptoLuKa developers
// Copyright (c) 2017, Intense Coin developers
// Copyright (c) 2012-2017, The CryptoNote developers, The Bytecoin developers
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

#include <cstddef>
#include <cstdint>
#include <limits>

namespace CryptoNote {
namespace parameters {

const uint64_t DIFFICULTY_TARGET                             = 90; // seconds
const uint32_t CRYPTONOTE_MAX_BLOCK_NUMBER                   = 500000000;
const size_t   CRYPTONOTE_MAX_BLOCK_BLOB_SIZE                = 5000000000;
const size_t   CRYPTONOTE_MAX_TX_SIZE                        = 1000000000;
const uint64_t CRYPTONOTE_PUBLIC_ADDRESS_BASE58_PREFIX       = 115; // addresses start with "L"
const uint32_t CRYPTONOTE_MINED_MONEY_UNLOCK_WINDOW          = 10;
const uint64_t CRYPTONOTE_BLOCK_FUTURE_TIME_LIMIT            = 270; // DIFFICULTY_TARGET * (DIFFICULTY_WINDOW_V4 - 1) / 20

const size_t   BLOCKCHAIN_TIMESTAMP_CHECK_WINDOW             = 60;
const size_t   BLOCKCHAIN_TIMESTAMP_CHECK_WINDOW_V4          = 11;

// MONEY_SUPPLY - total number coins to be generated
const uint64_t MONEY_SUPPLY									= UINT64_C(10000000000000000); // 100M
const uint64_t FINAL_SUBSIDY_PER_MINUTE						= UINT64_C(20000000); // 0.20 LUK
const unsigned EMISSION_SPEED_FACTOR                        = 22;
static_assert(EMISSION_SPEED_FACTOR <= 8 * sizeof(uint64_t), "Bad EMISSION_SPEED_FACTOR");

const size_t   CRYPTONOTE_REWARD_BLOCKS_WINDOW               	= 100;
const size_t   CRYPTONOTE_BLOCK_GRANTED_FULL_REWARD_ZONE     	= 1000000; //size of block (bytes) after which reward for block calculated using block size
const size_t   CRYPTONOTE_BLOCK_GRANTED_FULL_REWARD_ZONE_V2  	= 1000000;
const size_t   CRYPTONOTE_BLOCK_GRANTED_FULL_REWARD_ZONE_V1  	= 1000000;
const size_t   CRYPTONOTE_BLOCK_GRANTED_FULL_REWARD_ZONE_CURRENT = CRYPTONOTE_BLOCK_GRANTED_FULL_REWARD_ZONE;

const size_t   CRYPTONOTE_COINBASE_BLOB_RESERVED_SIZE        = 600;
const size_t   CRYPTONOTE_DISPLAY_DECIMAL_POINT              = 8;
const uint64_t MINIMUM_FEE                                   = UINT64_C(100000);    // pow(10, 5)
const uint64_t DEFAULT_DUST_THRESHOLD                        = UINT64_C(100000);    // pow(10, 5)

const uint64_t EXPECTED_NUMBER_OF_BLOCKS_PER_DAY             = 24 * 60 * 60 / DIFFICULTY_TARGET;
const size_t   DIFFICULTY_WINDOW                             = EXPECTED_NUMBER_OF_BLOCKS_PER_DAY; // blocks
const size_t   DIFFICULTY_CUT                                = 60;  // timestamps to cut after sorting
const size_t   DIFFICULTY_LAG                                = 15;
static_assert(2 * DIFFICULTY_CUT <= DIFFICULTY_WINDOW - 2, "Bad DIFFICULTY_WINDOW or DIFFICULTY_CUT");

const size_t  DIFFICULTY_BLOCKS_V2							 = 17;
const size_t  DIFFICULTY_CUT_V2								 = 6;
const size_t  DIFFICULTY_WINDOW_V2							 = DIFFICULTY_BLOCKS_V2 + DIFFICULTY_CUT_V2 * 2;
const size_t  DIFFICULTY_WINDOW_V4							 = 61;


const size_t   MAX_BLOCK_SIZE_INITIAL                        	= 100 * 1024;
const uint64_t MAX_BLOCK_SIZE_GROWTH_SPEED_NUMERATOR         	= 100 * 1024;
const uint64_t MAX_BLOCK_SIZE_GROWTH_SPEED_NUMERATOR_V2			= 35 * 100 * 1024;
const size_t   MAX_BLOCK_SIZE_ALLOWED_EVERY_N_BLOCK				= 5;
const uint64_t MAX_BLOCK_SIZE_GROWTH_SPEED_DENOMINATOR       	= 365 * 24 * 60 * 60 / DIFFICULTY_TARGET;

const uint64_t CRYPTONOTE_LOCKED_TX_ALLOWED_DELTA_BLOCKS     	= 1;
const uint64_t CRYPTONOTE_LOCKED_TX_ALLOWED_DELTA_SECONDS    	= DIFFICULTY_TARGET * CRYPTONOTE_LOCKED_TX_ALLOWED_DELTA_BLOCKS;

const uint64_t CRYPTONOTE_MEMPOOL_TX_LIVETIME                	= 60 * 60 * 24;     //seconds, one day
const uint64_t CRYPTONOTE_MEMPOOL_TX_FROM_ALT_BLOCK_LIVETIME 	= 60 * 60 * 24 * 7; //seconds, one week
const uint64_t CRYPTONOTE_NUMBER_OF_PERIODS_TO_FORGET_TX_DELETED_FROM_POOL = 7;  // CRYPTONOTE_NUMBER_OF_PERIODS_TO_FORGET_TX_DELETED_FROM_POOL * CRYPTONOTE_MEMPOOL_TX_LIVETIME = time to forget tx

const size_t   FUSION_TX_MAX_SIZE                            = CRYPTONOTE_BLOCK_GRANTED_FULL_REWARD_ZONE_CURRENT * 15 / 100;
const size_t   FUSION_TX_MIN_INPUT_COUNT                     = 12;
const size_t   FUSION_TX_MIN_IN_OUT_COUNT_RATIO              = 4;

const uint32_t KEY_IMAGE_CHECKING_BLOCK_INDEX                = 2000000;
const uint32_t UPGRADE_HEIGHT_V2                             = 100;
const uint32_t UPGRADE_HEIGHT_MAX_BLOCK_SIZE                 = 120;
const uint32_t UPGRADE_HEIGHT_V3                             = 200;
const uint32_t UPGRADE_HEIGHT_V4                             = 144999;
const unsigned UPGRADE_VOTING_THRESHOLD                      = 90;               // percent
const uint32_t UPGRADE_VOTING_WINDOW                         = EXPECTED_NUMBER_OF_BLOCKS_PER_DAY;  // blocks
const uint32_t UPGRADE_WINDOW                                = EXPECTED_NUMBER_OF_BLOCKS_PER_DAY;  // blocks

static_assert(0 < UPGRADE_VOTING_THRESHOLD && UPGRADE_VOTING_THRESHOLD <= 100, "Bad UPGRADE_VOTING_THRESHOLD");
static_assert(UPGRADE_VOTING_WINDOW > 1, "Bad UPGRADE_VOTING_WINDOW");

const char     CRYPTONOTE_BLOCKS_FILENAME[]                  	= "blocks.bin";
const char     CRYPTONOTE_BLOCKINDEXES_FILENAME[]            	= "blockindexes.bin";
const char     CRYPTONOTE_POOLDATA_FILENAME[]                	= "poolstate.bin";
const char     P2P_NET_DATA_FILENAME[]                       	= "p2pstate.bin";
const char     MINER_CONFIG_FILE_NAME[]                      	= "miner_conf.json";
} // parameters


const char     CRYPTONOTE_NAME[]                             = "Luka";

const uint8_t  TRANSACTION_VERSION_1                         =  1;
const uint8_t  TRANSACTION_VERSION_2                         =  2;
const uint8_t  CURRENT_TRANSACTION_VERSION                   =  TRANSACTION_VERSION_1;
const uint8_t  BLOCK_MAJOR_VERSION_1                         =  1;
const uint8_t  BLOCK_MAJOR_VERSION_2                         =  2;
const uint8_t  BLOCK_MAJOR_VERSION_3                         =  3;
const uint8_t  BLOCK_MAJOR_VERSION_4                         =  4;
const uint8_t  BLOCK_MINOR_VERSION_0                         =  0;
const uint8_t  BLOCK_MINOR_VERSION_1                         =  0;

const size_t   BLOCKS_IDS_SYNCHRONIZING_DEFAULT_COUNT        =  10000;  //by default, blocks ids count in synchronizing
const size_t   BLOCKS_SYNCHRONIZING_DEFAULT_COUNT            =  128;    //by default, blocks count in blocks downloading
const size_t   COMMAND_RPC_GET_BLOCKS_FAST_MAX_COUNT         =  1000;

const int      P2P_DEFAULT_PORT                              =  52420;
const int      RPC_DEFAULT_PORT                              =  52421;

const size_t   P2P_LOCAL_WHITE_PEERLIST_LIMIT                =  1000;
const size_t   P2P_LOCAL_GRAY_PEERLIST_LIMIT                 =  5000;

const size_t   P2P_CONNECTION_MAX_WRITE_BUFFER_SIZE          = 64 * 1024 * 1024; // 64 MB
const uint32_t P2P_DEFAULT_CONNECTIONS_COUNT                 = 8;
const size_t   P2P_DEFAULT_WHITELIST_CONNECTIONS_PERCENT     = 70;
const uint32_t P2P_DEFAULT_HANDSHAKE_INTERVAL                = 60;            // seconds
const uint32_t P2P_DEFAULT_PACKET_MAX_SIZE                   = 50000000;      // 50000000 bytes maximum packet size
const uint32_t P2P_DEFAULT_PEERS_IN_HANDSHAKE                = 250;
const uint32_t P2P_DEFAULT_CONNECTION_TIMEOUT                = 5000;          // 5 seconds
const uint32_t P2P_DEFAULT_PING_CONNECTION_TIMEOUT           = 2000;          // 2 seconds
const uint64_t P2P_DEFAULT_INVOKE_TIMEOUT                    = 60 * 2 * 1000; // 2 minutes
const size_t   P2P_DEFAULT_HANDSHAKE_INVOKE_TIMEOUT          = 5000;          // 5 seconds

const char     P2P_STAT_TRUSTED_PUB_KEY[] = "";

const char* const SEED_NODES[] = {
	"seed79.cryptoluka.cl:52420",
	"seed80.cryptoluka.cl:52420",
	"seed152.cryptoluka.cl:52420",
	"seed219.cryptoluka.cl:52420"
};

struct CheckpointData {
  uint32_t index;
  const char* blockId;
};

const CheckpointData CHECKPOINTS[] = {
	{ 0, "3e7b089856003ff9706e8db0a530bfec03d91143491086a2835fcdc2a38373e0"}, // Genesis
	{ 163, "b96a73c6d78c40ccd08e7f8578e2fb57395348eab0d0e5b4ad778783e89fa621"},
	{ 164, "57b496b43159e766da46cacf307e06183c3832e65225941b297bcd124e3c3e5b"}, // Dead Peer
	{ 165, "e15372c7a3ad29dbcf4009b4f9ed43586777b046650b81c2d56ca5dbc6a935e6"},
	{ 18000, "4a0fd7a883ca5a180aaec36cbc1c2c204ef2f703170851b61e1de035e32b1613"},
	{ 25900, "1183f7d7de6aaeae755e626614df0ef9610bf2df24d032bb7a1d0f9f2650a08a"},
	{ 27483, "7c485abdc0418ccab03ba2dc57087db89b83721744d2beb0a17cc7ae9e694f07"}, // Fork V1.2 - Emission
	{ 50000, "2e61795dd2e3cc5730299fc5f0ac51ecf97b4b5e798c71a212a101b549ca0a4c"}, // 50k
	{ 100000, "118b28b5e31a5f84c83cf3f08be5baee7605b0f600c92cfbf329f18a60658235"}, // 100k
	{ 117455, "fc4b46ea4d36c3ca8e0a98022afbf92c39754e6cdb0dbf4f2dba2af6af0966c6"},
  	{ 132200, "20a3112cf291a3f36ce7a7df3ced26b1d3676b4ff19d75af0d60c32fb75e5cba"}, // Fix Checkpoint
  	{ 145000, "13de5c33a257f60503b895e14dcc044da676631f190388f828751ab5c4078f0d"}, // 145k - LWMA 
  	{ 200000, "c916a3fe696c973320a2e101cd89580135772a71e0cd1d3a001ceca874e657ce"}, // 200k
	{ 250000, "c4c1a03e4375f73259c882e9c28e9e6f0a20348ce10cec2a5d2c72069f2e5a63"}, // 250k
	{ 300000, "fa4328093fc1f0162923533aaf256e496d7032d24697b2ccd27cbf83f2e3cae1"}, // 300k
	{ 315000, "3bb15575b5e639b477d9eaf3e0465e3c45be87ab5de049925425159454f8c282"}, // 315k
	{ 539200, "ed6e6e11b7d4dbedcaa3f8d4bff0435bc5cf6a09dd2ee32d852f08457abc95d3"} // 539200 - POW CHECK

};
}

#define ALLOW_DEBUG_COMMANDS
