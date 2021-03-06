// Copyright (c) 2010 Satoshi Nakamoto
// Copyright (c) 2009-2014 The Bitcoin developers
// Distributed under the MIT software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#include "chainparams.h"

#include <stdio.h>
#include "crypto/scrypt.h"
#include "random.h"
#include "util.h"
#include "utilstrencodings.h"

#include <assert.h>

#include <boost/assign/list_of.hpp>

using namespace std;
using namespace boost::assign;

struct SeedSpec6 {
    uint8_t addr[16];
    uint16_t port;
};

#include "chainparamsseeds.h"

/**
 * Main network
 */

//! Convert the pnSeeds6 array into usable address objects.
static void convertSeed6(std::vector<CAddress> &vSeedsOut, const SeedSpec6 *data, unsigned int count)
{
    // It'll only connect to one or two seed nodes because once it connects,
    // it'll get a pile of addresses with newer timestamps.
    // Seed nodes are given a random 'last seen time' of between one and two
    // weeks ago.
    const int64_t nOneWeek = 7*24*60*60;
    for (unsigned int i = 0; i < count; i++)
    {
        struct in6_addr ip;
        memcpy(&ip, data[i].addr, sizeof(ip));
        CAddress addr(CService(ip, data[i].port));
        addr.nTime = GetTime() - GetRand(nOneWeek) - nOneWeek;
        vSeedsOut.push_back(addr);
    }
}

/**
 * What makes a good checkpoint block?
 * + Is surrounded by blocks with reasonable timestamps
 *   (no blocks before with a timestamp after, none after with
 *    timestamp before)
 * + Contains no strange transactions
 */
static Checkpoints::MapCheckpoints mapCheckpoints =
        boost::assign::map_list_of
        //(,uint256(""))
        ( 0, uint256("2946a91685f253cd2ca29cde8cc35d7773cab280cdab4a075f613636e697aca4"))
        ( 5363, uint256("c5dd0d66a07c176a4463be3df7d9309986a3918b75935dde1c4769e4a64f9593"))
        ( 5369, uint256("dcd139890a39921876ab035eca34ee48c5239889f1dcdb8e3de3d097847f12d8"))
        ( 5380, uint256("b105b9cbb7b0ff4f2f6aef1d040c196edc2ab4318f7e6811a4373e8278cd5bb4"))
        ( 13899, uint256("883879d5325e48511e96557fff17df10123f062de23bc1f91f4e153154dbc764"))
        ( 14050, uint256("5be09cdd886573a50d543e3cca35a03eff2e46e4596bb2f509cede9e28dd33e9"))
        ( 22984, uint256("87ecfd9aa3c722132dd1786caa5ccb25b8ff821a3797aa0c424e10662aca509d"))
        ( 39986, uint256("9dba252fa6eebbf2b6c790965806c51916870bdf1e91bb7bf11eea55e64f12f8"))
        ( 49979, uint256("e564a2434f3acb7fe4af103927083fee3fa6429afa430e53b6eade3249dfe026"))
        ( 80493, uint256("6da822b8d4b5c060aee57523952630ac2262d5f56759ffc451ba6298b5fa423b"))
        ( 94458, uint256("084c2dec2c0da13e8f0143303d8f27ae79c81311ec804b2f746fbc1ad83bff14"))
        ( 136354,uint256("4f75d45e08213d5bb0584ce1e65666d47596cb8059b20d1c354b5bfd26309fbe"))
        (146221,uint256("c9d38afb57b0b25c822b1287197de413204cacfb27ca9c974772d8d8399737cb"))
        (146849,uint256("c5e18cab151a7eca95b02bd469c5a2aee301ef1b01e3b72add7f04a9c11f8b60"))
        (249936,uint256("6722b04059d14fce5f74eb4a9ea02784ae690c4985ba32801e2cf1f8b65582f3"))
        (279841,uint256("eb3bdef3524a2b0fd89f5480ac2a0a82108539b8e3156b598675e7109803cafa"))
        (319767,uint256("8fbcfa3dac1721fd899f4cf67a7381a86fdcfb5fb504e1729d6a9fe3b389a790"))
        (359900,uint256("fc4faa77d8e6c01941170e131125d5ebb5c9453fbaf3e6c2b0974b66c00f3bcd"))
        (499996,uint256("d28773f08f4747ff6e7e4d113753b5a79b60d905e59ae4046fa4b5ee9965badc"))
        (599825,uint256("0ddf7a53506b99acd201c13fba89b13837eb1707e97c27416f7513052cfd14af"))
        (699886,uint256("1663390cdccecaeea59f35affa91d04f57f9b790b8f1493b7f62d4de2279449a"))
        (809963,uint256("e7c094afaeaf37d20ce7d912b8353c41ac51c5219b1984acda32bfc889898203"))
        (1000293,uint256("40cb1f758e1c3f71b22326f0f9c610202600bd5f83aea5272f4a2d978d344163"))
        (1200283,uint256("6a1238c4d255d45d2669b83730b015ac0534e9e61af543fa66832c918747260f"))
        (1400278,uint256("5c75334308a26b9220b50b8d0adf06fed4921e7a2fbc2b5c551bb9a807533b9f"))
        (1600189,uint256("4b0608c7e733c1b6d2d660469f1b3c17be857ccb19d8e102f41503ab549e2f69"))
        (1800085,uint256("422e9d5dab710fae371a1e182243af38a49db0cfb3d075a5c67da2c4f35df9ef"))
        (2000124,uint256("34710dfebf36429ee09c7bd351671a2716f62f60fbbf9fb231be2314e88615ce"))
        (2100141,uint256("b449eb898b032e00ec87458991a5182cc541c3b479250ed0087860dc60980412"))
        //(,uint256(""))
        //(,uint256(""))
        //(,uint256(""))
        
        
        
        ;
/**TODO: calculate these for sexcoin **/
static const Checkpoints::CCheckpointData data = {
        &mapCheckpoints,
        1487294544, // * UNIX timestamp of last checkpoint block
        2818059,   // * total number of transactions between genesis and last checkpoint
                    //   (the tx=... number in the SetBestChain debug.log lines)
        60000.0     // * estimated number of transactions per day after checkpoint
    };

static Checkpoints::MapCheckpoints mapCheckpointsTestnet =
        boost::assign::map_list_of
        ( 0, uint256("0x73dc70a1698579360b62e724ecfeacfd938f45283162f3cf18f1b9eb3fc9fcd7"))
        ;
static const Checkpoints::CCheckpointData dataTestnet = {
        &mapCheckpointsTestnet,
        1473215502,
        0,
        60000.0
    };

static Checkpoints::MapCheckpoints mapCheckpointsRegtest =
        boost::assign::map_list_of
        ( 0, uint256("0f9188f13cb7b2c71f2a335e3a4fc328bf5beb436012afca590b1a11466e2206"))
        ;
static const Checkpoints::CCheckpointData dataRegtest = {
        &mapCheckpointsRegtest,
        0,
        0,
        0
    };
/**
  Sexcoin has been through a hard fork to fix the magic number problem, and then again to implement kimodo gravity well.
  In previous versions this was accomplished by implementing block height awareness and checking the incoming block height.
  We're going to fix that in this version. Right now we're plugging in the original chain parameters to get up and going, 
  then we'll deal with upgrading the chain and starting with KGW, with a process specifically designed to sync the client
  up past all the forks when initializing a new client chain.
  We are also going to take the time to get a testnet properly implemented.
  
**/
class CMainParams : public CChainParams {
public:
    CMainParams() {
        networkID = CBaseChainParams::MAIN;
        strNetworkID = "main";
        /** 
         * The message start string is designed to be unlikely to occur in normal data.
         * The characters are rarely used upper ASCII, not valid as UTF-8, and produce
         * a large 4-byte int at any alignment.
         */
        pchMessageStart[0] = 0xfa;
        pchMessageStart[1] = 0xce;
        pchMessageStart[2] = 0x69;
        pchMessageStart[3] = 0x69;
        vAlertPubKey = ParseHex("04627903b58520074e77d1f6788407167655cd49b93c4030dd104ec57ed37f0ae5a40bcc551652d732a48fda7db327b4c6094ad19651c61d8b19bcf661ef4bfeaf");
        nDefaultPort = 9560;
        bnProofOfWorkLimit = ~uint256(0) >> 5;
        nSubsidyHalvingInterval = 600000;
        
        /** TODO: will these work for sexcoin **/
        nEnforceBlockUpgradeMajority = 750;
        nRejectBlockOutdatedMajority = 950;
        nToCheckBlockUpgradeMajority = 1000;

        nMinerThreads = 0;
        nTargetTimespan = 8 * 60 * 60; // 8 hour
        nTargetSpacing = 1 * 60; // 1 minute
        nMaxTipAge = 24 * 60 * 60; // 1 day

        /**
         * Build the genesis block. Note that the output of the genesis coinbase cannot
         * be spent as it did not originally exist in the database.
         * 
         * CBlock(hash=000000000019d6, ver=1, hashPrevBlock=00000000000000, hashMerkleRoot=4a5e1e, nTime=1231006505, nBits=1d00ffff, nNonce=2083236893, vtx=1)
         *   CTransaction(hash=4a5e1e, ver=1, vin.size=1, vout.size=1, nLockTime=0)
         *     CTxIn(COutPoint(000000, -1), coinbase 04ffff001d0104455468652054696d65732030332f4a616e2f32303039204368616e63656c6c6f72206f6e206272696e6b206f66207365636f6e64206261696c6f757420666f722062616e6b73)
         *     CTxOut(nValue=50.00000000, scriptPubKey=0x5F1DF16B2B704C8A578D0B)
         *   vMerkleTree: 4a5e1e
         */
        const char* pszTimestamp = "Disaster from the sky in Oklahoma";
        CMutableTransaction txNew;
        txNew.vin.resize(1);
        txNew.vout.resize(1);
        txNew.vin[0].scriptSig = CScript() << 486604799 << CScriptNum(4) << vector<unsigned char>((const unsigned char*)pszTimestamp, (const unsigned char*)pszTimestamp + strlen(pszTimestamp));
        txNew.vout[0].nValue = 50 * COIN;
        txNew.vout[0].scriptPubKey = CScript() << ParseHex("04a5814813115273a109cff99907ba4a05d951873dae7acb6c973d0c9e7c88911a3dbc9aa600deac241b91707e7b4ffb30ad91c8e56e695a1ddf318592988afe0a") << OP_CHECKSIG;
        genesis.vtx.push_back(txNew);
        genesis.hashPrevBlock = 0;
        genesis.hashMerkleRoot = genesis.BuildMerkleTree();
        genesis.nVersion = 1;
        genesis.nTime    = 1369146359;
        genesis.nBits    = 0x1e7fffff;
        genesis.nNonce   = 244086;

        hashGenesisBlock = genesis.GetHash();
        assert(hashGenesisBlock == uint256("0xf42b9553085a1af63d659d3907a42c3a0052bbfa2693d3acf990af85755f2279"));
        assert(genesis.hashMerkleRoot == uint256("0x661de12dc8dd26989adb169733b5a99150d52b8b6e8332976277856e246101f4"));

        vSeeds.push_back(CDNSSeedData("sexcoin.info", "dnsseed.sexcoin.info"));
        vSeeds.push_back(CDNSSeedData("lavajumper.com", "dnsseed.lavajumper.com"));
        /*
		vSeeds.push_back(CDNSSeedData("litecoinpool.org", "dnsseed.litecoinpool.org"));
		*/

        base58Prefixes[PUBKEY_ADDRESS] = list_of(62);
        base58Prefixes[SCRIPT_ADDRESS] = list_of(5);
        base58Prefixes[SECRET_KEY] =     list_of(190);
        base58Prefixes[EXT_PUBLIC_KEY] = list_of(0x04)(0x88)(0xB2)(0x1E);
        base58Prefixes[EXT_SECRET_KEY] = list_of(0x04)(0x88)(0xAD)(0xE4);

        convertSeed6(vFixedSeeds, pnSeed6_main, ARRAYLEN(pnSeed6_main));

        fRequireRPCPassword = true;
        fMiningRequiresPeers = true;
        fAllowMinDifficultyBlocks = false;
        fDefaultConsistencyChecks = false;
        fRequireStandard = true;
        fMineBlocksOnDemand = false;
        fSkipProofOfWorkCheck = false;
        fTestnetToBeDeprecatedFieldRPC = false;

        // Litecoin: Mainnet v2 enforced as of block 710k
        // Sexcoin: Mainnet is switching straight to V4, we're going to use this to enforce.
        // initial guess is that we should accept V1 blocks for a short time, but then reject outright.
        // unfortunately, KGW has caused block solve times to be shorter than expected
        // arbitrary guess: 2,300,000;
        // 60 * 24 = 1440 blocks/day
        // * 30 days = 43200 block for 1 month in the future.
        // * 1.4 to adjust for observed block rate = 56160
        nEnforceV2AfterHeight = 2348569; // ~ 30 days from 2017-06-20 
    }

    const Checkpoints::CCheckpointData& Checkpoints() const 
    {
        return data;
    }
};
static CMainParams mainParams;

/**
 * Testnet (v3)
 */
class CTestNetParams : public CMainParams {
public:
    CTestNetParams() {
        networkID = CBaseChainParams::TESTNET;
        strNetworkID = "test";
        pchMessageStart[0] = 0xfa;
        pchMessageStart[1] = 0xce;
        pchMessageStart[2] = 0x96;
        pchMessageStart[3] = 0x69;
        vAlertPubKey = ParseHex("0449623fc74489a947c4b15d579115591add020e53b3490bf47297dfa3762250625f8ecc2fb4fc59f69bdce8f7080f3167808276ed2c79d297054367566038aa82");
        nDefaultPort = 19560;
        nEnforceBlockUpgradeMajority = 51;
        nRejectBlockOutdatedMajority = 75;
        nToCheckBlockUpgradeMajority = 100;
        nMinerThreads = 0;
        nTargetTimespan = 8 * 60 * 60; // 3.5 days
        nTargetSpacing = 1 * 60; // 2.5 minutes
        nMaxTipAge = 0x7fffffff;

        //! Modify the testnet genesis block so the timestamp is valid for a later start.
        genesis.nTime = 1473215502; //1369146359=old testnet nTime;
        genesis.nNonce = 517454;
        hashGenesisBlock = genesis.GetHash();
        
        /**
        // Sexcoin is generating a new testnet genesis. This code will only be used once
        // check that genesis block is valid
        bool fNegative;
        bool fOverflow;
        uint256 bnTarget;
        bnTarget.SetCompact(genesis.nBits, &fNegative, &fOverflow);
        
        if (hashGenesisBlock > bnTarget)
            genesis = FindNewGenesisBlock(genesis);
        
        // end of one use code
        **/
        
        assert(hashGenesisBlock == uint256("0x73dc70a1698579360b62e724ecfeacfd938f45283162f3cf18f1b9eb3fc9fcd7"));

        vFixedSeeds.clear();
        vSeeds.clear();
        vSeeds.push_back(CDNSSeedData("sexcoin.info", "testnet-seed.sexcoin.info"));
        //vSeeds.push_back(CDNSSeedData("xurious.com", "testnet-seed.ltc.xurious.com"));
        //vSeeds.push_back(CDNSSeedData("wemine-testnet.com", "dnsseed.wemine-testnet.com"));

        base58Prefixes[PUBKEY_ADDRESS] = list_of(124);
        base58Prefixes[SCRIPT_ADDRESS] = list_of(196);
        base58Prefixes[SECRET_KEY]     = list_of(239);
        base58Prefixes[EXT_PUBLIC_KEY] = list_of(0x04)(0x35)(0x87)(0xCF);
        base58Prefixes[EXT_SECRET_KEY] = list_of(0x04)(0x35)(0x83)(0x94);

        convertSeed6(vFixedSeeds, pnSeed6_test, ARRAYLEN(pnSeed6_test));

        fRequireRPCPassword = true;
        fMiningRequiresPeers = true;
        fAllowMinDifficultyBlocks = true;
        fDefaultConsistencyChecks = false;
        fRequireStandard = false;
        fMineBlocksOnDemand = false;
        fTestnetToBeDeprecatedFieldRPC = true;

        // Litecoin: Testnet v2 enforced as of block 400k
        nEnforceV2AfterHeight = 400000;
    }
    const Checkpoints::CCheckpointData& Checkpoints() const 
    {
        return dataTestnet;
    }
};
static CTestNetParams testNetParams;

/**
 * Regression test
 */
class CRegTestParams : public CTestNetParams {
public:
    CRegTestParams() {
        networkID = CBaseChainParams::REGTEST;
        strNetworkID = "regtest";
        pchMessageStart[0] = 0xfa;
        pchMessageStart[1] = 0xce;
        pchMessageStart[2] = 0x99;
        pchMessageStart[3] = 0x99;
        nSubsidyHalvingInterval = 900;
        nEnforceBlockUpgradeMajority = 750;
        nRejectBlockOutdatedMajority = 950;
        nToCheckBlockUpgradeMajority = 1000;
        nMinerThreads = 1;
        nTargetTimespan = 8 * 60 * 60; // 3.5 days
        nTargetSpacing = 60; // 2.5 minutes
        bnProofOfWorkLimit = ~uint256(0) >> 1;
        nMaxTipAge = 24 * 60 * 60;
        genesis.nTime = 1296688602;
        genesis.nBits = 0x207fffff;
        genesis.nNonce = 0;
        hashGenesisBlock = genesis.GetHash();
        nDefaultPort = 19569;
        //assert(hashGenesisBlock == uint256("0x530827f38f93b43ed12af0b3ad25a288dc02ed74d6d7857862df51fc56c416f9"));

        vFixedSeeds.clear(); //! Regtest mode doesn't have any fixed seeds.
        vSeeds.clear();  //! Regtest mode doesn't have any DNS seeds.

        fRequireRPCPassword = false;
        fMiningRequiresPeers = false;
        fAllowMinDifficultyBlocks = true;
        fDefaultConsistencyChecks = true;
        fRequireStandard = false;
        fMineBlocksOnDemand = true;
        fTestnetToBeDeprecatedFieldRPC = false;

        // Litecoin: v2 enforced using Bitcoin's supermajority rule
        nEnforceV2AfterHeight = -1;
    }
    const Checkpoints::CCheckpointData& Checkpoints() const 
    {
        return dataRegtest;
    }
};
static CRegTestParams regTestParams;

/**
 * Unit test
 */
class CUnitTestParams : public CMainParams, public CModifiableParams {
public:
    CUnitTestParams() {
        networkID = CBaseChainParams::UNITTEST;
        strNetworkID = "unittest";
        nDefaultPort = 18569;
        vFixedSeeds.clear(); //! Unit test mode doesn't have any fixed seeds.
        vSeeds.clear();  //! Unit test mode doesn't have any DNS seeds.

        fRequireRPCPassword = false;
        fMiningRequiresPeers = false;
        fDefaultConsistencyChecks = true;
        fAllowMinDifficultyBlocks = false;
        fMineBlocksOnDemand = true;

        // Litecoin: v2 enforced using Bitcoin's supermajority rule
        nEnforceV2AfterHeight = -1;
    }

    const Checkpoints::CCheckpointData& Checkpoints() const 
    {
        // UnitTest share the same checkpoints as MAIN
        return data;
    }

    //! Published setters to allow changing values in unit test cases
    virtual void setSubsidyHalvingInterval(int anSubsidyHalvingInterval)  { nSubsidyHalvingInterval=anSubsidyHalvingInterval; }
    virtual void setEnforceBlockUpgradeMajority(int anEnforceBlockUpgradeMajority)  { nEnforceBlockUpgradeMajority=anEnforceBlockUpgradeMajority; }
    virtual void setRejectBlockOutdatedMajority(int anRejectBlockOutdatedMajority)  { nRejectBlockOutdatedMajority=anRejectBlockOutdatedMajority; }
    virtual void setToCheckBlockUpgradeMajority(int anToCheckBlockUpgradeMajority)  { nToCheckBlockUpgradeMajority=anToCheckBlockUpgradeMajority; }
    virtual void setDefaultConsistencyChecks(bool afDefaultConsistencyChecks)  { fDefaultConsistencyChecks=afDefaultConsistencyChecks; }
    virtual void setAllowMinDifficultyBlocks(bool afAllowMinDifficultyBlocks) {  fAllowMinDifficultyBlocks=afAllowMinDifficultyBlocks; }
    virtual void setSkipProofOfWorkCheck(bool afSkipProofOfWorkCheck) { fSkipProofOfWorkCheck = afSkipProofOfWorkCheck; }
};
static CUnitTestParams unitTestParams;


static CChainParams *pCurrentParams = 0;

CModifiableParams *ModifiableParams()
{
   assert(pCurrentParams);
   assert(pCurrentParams==&unitTestParams);
   return (CModifiableParams*)&unitTestParams;
}

const CChainParams &Params() {
    assert(pCurrentParams);
    return *pCurrentParams;
}

CChainParams &Params(CBaseChainParams::Network network) {
    switch (network) {
        case CBaseChainParams::MAIN:
            return mainParams;
        case CBaseChainParams::TESTNET:
            return testNetParams;
        case CBaseChainParams::REGTEST:
            return regTestParams;
        case CBaseChainParams::UNITTEST:
            return unitTestParams;
        default:
            assert(false && "Unimplemented network");
            return mainParams;
    }
}

void SelectParams(CBaseChainParams::Network network) {
    SelectBaseParams(network);
    pCurrentParams = &Params(network);
}

bool SelectParamsFromCommandLine()
{
    CBaseChainParams::Network network = NetworkIdFromCommandLine();
    if (network == CBaseChainParams::MAX_NETWORK_TYPES)
        return false;

    SelectParams(network);
    return true;
}

CBlock CChainParams::FindNewGenesisBlock(CBlock block){
    // if this gets called, it means the genesis block has failed the nBits POW test
    // we need to mine a new one that works. Just like mining, we loop through changing
    // nonces until we get a hash low enough to satisfy the nBits
   
    bool fNegative;
    bool fOverflow;
    uint256 hashTarget; 
    uint256 thash;
    char scratchpad[SCRYPT_SCRATCHPAD_SIZE];
    
    hashTarget.SetCompact(block.nBits, &fNegative, &fOverflow);
    printf("Finding new Genesis Block...\n");
    while(true)
    {
#if defined(USE_SSE2)
        // Detection would work, but in cases where we KNOW it always has SSE2,
        // it is faster to use directly than to use a function pointer or conditional.
#if defined(_M_X64) || defined(__x86_64__) || defined(_M_AMD64) || (defined(MAC_OSX) && defined(__i386__))
        // Always SSE2: x86_64 or Intel MacOS X
        scrypt_1024_1_1_256_sp_sse2(BEGIN(block.nVersion), BEGIN(thash), scratchpad);
#else
        // Detect SSE2: 32bit x86 Linux or Windows
        scrypt_1024_1_1_256_sp(BEGIN(block.nVersion), BEGIN(thash), scratchpad);
#endif
#else
       // Generic scrypt
        scrypt_1024_1_1_256_sp_generic(BEGIN(block.nVersion), BEGIN(thash), scratchpad);
#endif

        if (thash <= hashTarget)
            break;
        if ((block.nNonce & 0xFFF) == 0)
        {
            printf("nonce %08X: hash = %s (target = %s)\n", block.nNonce, thash.ToString().c_str(), hashTarget.ToString().c_str());
        }
        ++block.nNonce;
        if (block.nNonce == 0)
        {
            printf("NONCE WRAPPED, incrementing time\n");
            ++block.nTime;
        }
    }
    printf("block.nTime = %u \n", block.nTime);
    printf("block.nNonce = %u \n", block.nNonce);
    printf("block.GetHash = %s\n", block.GetHash().ToString().c_str());
    
    return(block);
}
