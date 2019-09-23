// Copyright (c) 2010 Satoshi Nakamoto
// Copyright (c) 2009-2014 The Bitcoin developers
// Copyright (c) 2014-2015 The Dash developers
// Copyright (c) 2015-2017 The PIVX developers
// Copyright (c) 2019 The AileCoin Developers
// Distributed under the MIT software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#include "chainparams.h"
#include "bignum.h"
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
static void convertSeed6(std::vector<CAddress>& vSeedsOut, const SeedSpec6* data, unsigned int count)
{
    // It'll only connect to one or two seed nodes because once it connects,
    // it'll get a pile of addresses with newer timestamps.
    // Seed nodes are given a random 'last seen time' of between one and two
    // weeks ago.
    const int64_t nOneWeek = 7 * 24 * 60 * 60;
    for (unsigned int i = 0; i < count; i++) {
        struct in6_addr ip;
        memcpy(&ip, data[i].addr, sizeof(ip));
        CAddress addr(CService(ip, data[i].port));
        addr.nTime = GetTime() - GetRand(nOneWeek) - nOneWeek;
        vSeedsOut.push_back(addr);
    }
}

//   What makes a good checkpoint block?
// + Is surrounded by blocks with reasonable timestamps
//   (no blocks before with a timestamp after, none after with
//    timestamp before)
// + Contains no strange transactions
static Checkpoints::MapCheckpoints mapCheckpoints =
    boost::assign::map_list_of
    (     0, uint256("0x0000022334a1cd7f9cfd9aeefb0563ebd585d6206d1dffde78cd6db24967e402"))
    (    20, uint256("0x000006d806dc742f88c22774e5e983f3116d9b3bd3386335da27f7e1982b5c22"))
    (  4740, uint256("0x94687b000606babc37a1e795e213dcb7ced9752cf07670cd066191b88a9004ad"))
    (  5535, uint256("0x3cfa27266fe9382fdb58231ed440832fac9df3cb5bd491f364aaa1fe2895c9ab"));



static const Checkpoints::CCheckpointData data = {
    &mapCheckpoints,
    1562683961, // * UNIX timestamp of last checkpoint block
    10788,      // * total number of transactions between genesis and last checkpoint (the tx=... number in the SetBestChain debug.log lines)
																			
    1440        // * estimated number of transactions per day after checkpoint
};

static Checkpoints::MapCheckpoints mapCheckpointsTestnet =
    boost::assign::map_list_of(0, uint256("0x0000022334a1cd7f9cfd9aeefb0563ebd585d6206d1dffde78cd6db24967e402"));

static const Checkpoints::CCheckpointData dataTestnet = {
    &mapCheckpointsTestnet,
    1562155595, // * UNIX timestamp of last checkpoint block
    0,          // * total number of transactions between genesis and last checkpoint (the tx=... number in the SetBestChain debug.log lines)
    1440        // * estimated number of transactions per day after checkpoint
};

static Checkpoints::MapCheckpoints mapCheckpointsRegtest =
    boost::assign::map_list_of(0, uint256("0x0000022334a1cd7f9cfd9aeefb0563ebd585d6206d1dffde78cd6db24967e402"));
static const Checkpoints::CCheckpointData dataRegtest = {
    &mapCheckpointsRegtest,
    1562155595, // * UNIX timestamp of last checkpoint block
    0,          // * total number of transactions between genesis and last checkpoint (the tx=... number in the SetBestChain debug.log lines)
    1440        // * estimated number of transactions per day after checkpoint
};

class CMainParams : public CChainParams
{
public:
    CMainParams()
    {
        networkID                      = CBaseChainParams::MAIN;
        strNetworkID                   = "main";

        /**
         * The message start string is designed to be unlikely to occur in normal data.
         * The characters are rarely used upper ASCII, not valid as UTF-8, and produce
         * a large 4-byte int at any alignment.
         */
        pchMessageStart[0]             = 0x91;
        pchMessageStart[1]             = 0xcd;
        pchMessageStart[2]             = 0xdf;
        pchMessageStart[3]             = 0x9e;
        vAlertPubKey                   = ParseHex("048088368a4d50324ff5687c90d0234ce989cdfbeb7632e757c87dfbbbf86d27499623adf2c3c5c6a810ab8f316e5ab59866a9730c1b649ccc91850aa9e0239177");
        nDefaultPort                   = 59871;
        nSubsidyHalvingInterval        = 1050000;
        nMaxReorganizationDepth        = 100;
        nEnforceBlockUpgradeMajority   = 750;
        nRejectBlockOutdatedMajority   = 950;
        nToCheckBlockUpgradeMajority   = 1000;
        nMinerThreads                  = 0;

        bnProofOfWorkLimit             = ~uint256(0) >> 20;	// AileCoin starting difficulty is 1 / 2^12
        nTargetTimespan                =  1 * 60;
        nTargetSpacing                 =  1 * 60;			// AileCoin: 1 minute blocks during POW

        bnProofOfStakeLimit            = ~uint256(0) >> 20;	// AileCoin starting difficulty is 1 / 2^12
        nTargetTimespanPOS             = 40 * 60;
        nTargetSpacingPOS              =  1 * 60;			// AileCoin: 1 minute blocks during POS

        nMaturity                      = 5;
        nMasternodeCountDrift          = 20;
        nMaxMoneyOut                   = 1000000000 * COIN;

        /** Height or Time Based Activations **/
        nLastPOWBlock                  = 300;
        nModifierUpdateBlock           = 1;

        const char* pszTimestamp       = "Ailecoin by TERRA MILESTONE";
        CMutableTransaction txNew;
        txNew.vin.resize(1);
        txNew.vout.resize(1);
        txNew.vin[0].scriptSig         = CScript() << 486604799 << CScriptNum(4) << vector<unsigned char>((const unsigned char*)pszTimestamp, (const unsigned char*)pszTimestamp + strlen(pszTimestamp));
        txNew.vout[0].nValue           = 0 * COIN;
        txNew.vout[0].scriptPubKey     = CScript() << ParseHex("04830e847dd05ba25d5be89d323775f9b632598e458acc2a5a528738de0692a9784693d3e49e2fd5603a527bea67b8ed9ee1ec84546ac7026e5e0ca976bd2ad4cf") << OP_CHECKSIG;
        genesis.vtx.push_back(txNew);
        genesis.hashPrevBlock          = 0;
        genesis.hashMerkleRoot         = genesis.BuildMerkleTree();
        genesis.nVersion               = 1;
        genesis.nTime                  = 1568764800; //09/18/2019 @ 12:00am (UTC)
        genesis.nBits                  = 504365040;
        genesis.nNonce                 = 3295626318;

        hashGenesisBlock               = genesis.GetHash();
		
		printf("genesis.GetHash = %s\n", genesis.GetHash().ToString().c_str());
		printf("genesis.hashMerkleRoot = %s\n", genesis.BuildMerkleTree().ToString().c_str());
        assert(hashGenesisBlock        == uint256("0xc7f4deaf2e9acb339facb15b9128db7c385125a09ca17cee9262841a0866495b"));
        assert(genesis.hashMerkleRoot  == uint256("0x720db66236cbc0145824aa7a04758efa1a126da1ed4d8e2ce3d48d2ec7927026"));

        base58Prefixes[PUBKEY_ADDRESS] = std::vector<unsigned char>(1,  48);	//48 L https://en.bitcoin.it/wiki/List_of_address_prefixes
        base58Prefixes[SCRIPT_ADDRESS] = std::vector<unsigned char>(1,  63);
        base58Prefixes[SECRET_KEY]     = std::vector<unsigned char>(1, 193);

        base58Prefixes[EXT_PUBLIC_KEY] = boost::assign::list_of(0x04)(0x88)(0xB2)(0x1E).convert_to_container<std::vector<unsigned char> >(); // AileCoin BIP32 pubkeys start with 'xpub' (Bitcoin defaults)
        base58Prefixes[EXT_SECRET_KEY] = boost::assign::list_of(0x04)(0x88)(0xAD)(0xE4).convert_to_container<std::vector<unsigned char> >(); // AileCoin BIP32 prvkeys start with 'xprv' (Bitcoin defaults)
        base58Prefixes[EXT_COIN_TYPE]  = boost::assign::list_of(0x80)(0x00)(0x92)(0xf1).convert_to_container<std::vector<unsigned char> >(); // BIP44 coin type is from https://github.com/satoshilabs/slips/blob/master/slip-0044.md 109 	0x800092f1

        vFixedSeeds.clear();
        vSeeds.clear();

        convertSeed6(vFixedSeeds, pnSeed6_main, ARRAYLEN(pnSeed6_main));

        vSeeds.push_back(CDNSSeedData("dnsseed.ailecoin.com", "dnsseed.ailecoin.com"));
		vSeeds.push_back(CDNSSeedData("dnsseed.ailecoin.net", "dnsseed.ailecoin.net"));
        vSeeds.push_back(CDNSSeedData("dnsseed.ailecoin.io", "dnsseed.ailecoin.io"));
		vSeeds.push_back(CDNSSeedData("dnsseed.ailecoin.kr", "dnsseed.ailecoin.kr"));
		vSeeds.push_back(CDNSSeedData("dnsseed.ailecoin.co.kr", "dnsseed.ailecoin.co.kr"));

        fMiningRequiresPeers           = true;
        fAllowMinDifficultyBlocks      = false;
        fDefaultConsistencyChecks      = false;
        fRequireStandard               = true;
        fMineBlocksOnDemand            = false;
        fSkipProofOfWorkCheck          = false;
        fTestnetToBeDeprecatedFieldRPC = false;
        fHeadersFirstSyncingActive     = false;

        nPoolMaxTransactions           = 3;
        strSporkKey                    = "04d3097909c5ce64683adca06b8b91fe26ad90a935836aaedc57ead8aed1419ae241fcecbeebb7302f2d882c788956807218ffb9a8e7bb80ea7cd57fad9dddb8ad";
        strMasternodePoolDummyAddress  = "PFQP91e8KTxJu2yzDnyjW9VPXyxBHYK3kF";
        nStartMasternodePayments       = genesis.nTime + 86400; // 24 hours after genesis
        nBudget_Fee_Confirmations      = 6;						// Number of confirmations for the finalization fee.

        strTreasuryAddress             = "PBfFbtNy8ybUEyJB7Ep5SCyjw3xwzsqMiy";
	 
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
class CTestNetParams : public CMainParams
{
public:
    CTestNetParams()
    {
        networkID                      = CBaseChainParams::TESTNET;
        strNetworkID                   = "test";
        pchMessageStart[0]             = 0xb4;
        pchMessageStart[1]             = 0x2c;
        pchMessageStart[2]             = 0xcc;
        pchMessageStart[3]             = 0xfe;
        vAlertPubKey                   = ParseHex("04e1480f1dff5a015120b1470901deb7609cede241c5b52eef509559f252f98c6079fbdedf4cdea68071175fa82cc4fe9bbbc4cc27db16c5384caea3e3955ea69c");
        nDefaultPort                   = 59874;
        nEnforceBlockUpgradeMajority   = 51;
        nRejectBlockOutdatedMajority   = 75;
        nToCheckBlockUpgradeMajority   = 100;
        nMinerThreads                  = 0;

        bnProofOfWorkLimit             = ~uint256(0) >> 20;
        nTargetTimespan                =  1 * 60;
        nTargetSpacing                 =  1 * 60;  // AileCoin: 1 minute blocks during POW

        bnProofOfStakeLimit            = ~uint256(0) >> 20;
        nTargetTimespanPOS             =  40 * 60;
        nTargetSpacingPOS              =   1 * 60;  // AileCoin: 1 minute blocks during POS

        nLastPOWBlock                  = 100;
        nMaturity                      = 5;
        nMasternodeCountDrift          = 4;
        nModifierUpdateBlock           = 1;
        nMaxMoneyOut                   = 30000000 * COIN;

        //! Modify the testnet genesis block so the timestamp is valid for a later start.
        genesis.nTime                  = 1568764800;
        genesis.nNonce                 = 3295626318;

        hashGenesisBlock               = genesis.GetHash();
        assert(hashGenesisBlock        == uint256("0x0000000075efe8629a1c9d7c3c561ceb2f022f4f7c6354733d0342e5930ccb8e"));
        assert(genesis.hashMerkleRoot  == uint256("0x720db66236cbc0145824aa7a04758efa1a126da1ed4d8e2ce3d48d2ec7927026"));

        base58Prefixes[PUBKEY_ADDRESS] = std::vector<unsigned char>(1,  83);	// 83 a
        base58Prefixes[SCRIPT_ADDRESS] = std::vector<unsigned char>(1, 125);
        base58Prefixes[SECRET_KEY]     = std::vector<unsigned char>(1, 193);


        base58Prefixes[EXT_PUBLIC_KEY] = boost::assign::list_of(0x04)(0x88)(0xB2)(0x1E).convert_to_container<std::vector<unsigned char> >();	// AileCoin BIP32 pubkeys start with 'xpub' (Bitcoin defaults)
        base58Prefixes[EXT_SECRET_KEY] = boost::assign::list_of(0x04)(0x88)(0xAD)(0xE4).convert_to_container<std::vector<unsigned char> >();	// AileCoin BIP32 prvkeys start with 'xprv' (Bitcoin defaults)
        base58Prefixes[EXT_COIN_TYPE]  = boost::assign::list_of(0x80)(0x00)(0x00)(0x01).convert_to_container<std::vector<unsigned char> >();	// Testnet AileCoin BIP44 coin type is '1' (All coin's testnet default)

        convertSeed6(vFixedSeeds, pnSeed6_test, ARRAYLEN(pnSeed6_test));

        fMiningRequiresPeers           = true;
        fAllowMinDifficultyBlocks      = false;
        fDefaultConsistencyChecks      = false;
        fRequireStandard               = false;
        fMineBlocksOnDemand            = false;
        fTestnetToBeDeprecatedFieldRPC = true;

        nPoolMaxTransactions           = 2;
        strSporkKey                    = "04b73b498dfd490c4dff95125c43e5ed1e19cf61d15628d72a9e5ceaeb93ade10d2375a60d8561cb960db6f03e53be3873efc6f6ec826a7d6b3fcfac288cc5a295";
        strMasternodePoolDummyAddress  = "PFQP91e8KTxJu2yzDnyjW9VPXyxBHYK3kF";
        nStartMasternodePayments       = genesis.nTime + 86400; // 24 hours after genesis
        nBudget_Fee_Confirmations      = 3; // Number of confirmations for the finalization fee. We have to make this very short
                                       // here because we only have a 8 block finalization window on testnet

        strTreasuryAddress             = "PBfFbtNy8ybUEyJB7Ep5SCyjw3xwzsqMiy";
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
class CRegTestParams : public CTestNetParams
{
public:
    CRegTestParams()
    {
        networkID = CBaseChainParams::REGTEST;
        strNetworkID = "regtest";
        strNetworkID = "regtest";
        pchMessageStart[0] = 0x21;
        pchMessageStart[1] = 0xef;
        pchMessageStart[2] = 0x33;
        pchMessageStart[3] = 0xbd;
									  
        nSubsidyHalvingInterval = 150;
        nEnforceBlockUpgradeMajority = 750;
        nRejectBlockOutdatedMajority = 950;
        nToCheckBlockUpgradeMajority = 1000;
        nMinerThreads = 1;
        nTargetTimespan = 24 * 60 * 60; // AileCoin: 1 day
        nTargetSpacing = 1 * 60;        // AileCoin: 1 minutes
        bnProofOfWorkLimit = ~uint256(0) >> 1;
        genesis.nTime = 1516926684;
        genesis.nBits = 0x207fffff;
        genesis.nNonce = 20542300;

        hashGenesisBlock = genesis.GetHash();
        nDefaultPort = 59876;
       // assert(hashGenesisBlock == uint256("0x0000022334a1cd7f9cfd9aeefb0563ebd585d6206d1dffde78cd6db24967e402"));

        vFixedSeeds.clear(); //! Regtest mode doesn't have any fixed seeds.
        vSeeds.clear();      //! Regtest mode doesn't have any DNS seeds.

        fMiningRequiresPeers = false;
        fAllowMinDifficultyBlocks = true;
        fDefaultConsistencyChecks = true;
        fRequireStandard = false;
        fMineBlocksOnDemand = true;
        fTestnetToBeDeprecatedFieldRPC = false;
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
class CUnitTestParams : public CMainParams, public CModifiableParams
{
public:
    CUnitTestParams()
    {
        networkID = CBaseChainParams::UNITTEST;
        strNetworkID = "unittest";
        nDefaultPort = 59878;
        vFixedSeeds.clear(); //! Unit test mode doesn't have any fixed seeds.
        vSeeds.clear();      //! Unit test mode doesn't have any DNS seeds.

        fMiningRequiresPeers = false;
        fDefaultConsistencyChecks = true;
        fAllowMinDifficultyBlocks = false;
        fMineBlocksOnDemand = true;
    }

    const Checkpoints::CCheckpointData& Checkpoints() const
    {
        // UnitTest share the same checkpoints as MAIN
        return data;
    }

    //! Published setters to allow changing values in unit test cases
    virtual void setSubsidyHalvingInterval(int anSubsidyHalvingInterval) { nSubsidyHalvingInterval = anSubsidyHalvingInterval; }
    virtual void setEnforceBlockUpgradeMajority(int anEnforceBlockUpgradeMajority) { nEnforceBlockUpgradeMajority = anEnforceBlockUpgradeMajority; }
    virtual void setRejectBlockOutdatedMajority(int anRejectBlockOutdatedMajority) { nRejectBlockOutdatedMajority = anRejectBlockOutdatedMajority; }
    virtual void setToCheckBlockUpgradeMajority(int anToCheckBlockUpgradeMajority) { nToCheckBlockUpgradeMajority = anToCheckBlockUpgradeMajority; }
    virtual void setDefaultConsistencyChecks(bool afDefaultConsistencyChecks) { fDefaultConsistencyChecks = afDefaultConsistencyChecks; }
    virtual void setAllowMinDifficultyBlocks(bool afAllowMinDifficultyBlocks) { fAllowMinDifficultyBlocks = afAllowMinDifficultyBlocks; }
    virtual void setSkipProofOfWorkCheck(bool afSkipProofOfWorkCheck) { fSkipProofOfWorkCheck = afSkipProofOfWorkCheck; }
};
static CUnitTestParams unitTestParams;


static CChainParams* pCurrentParams = 0;

CModifiableParams* ModifiableParams()
{
    assert(pCurrentParams);
    assert(pCurrentParams == &unitTestParams);
    return (CModifiableParams*)&unitTestParams;
}

const CChainParams& Params()
{
    assert(pCurrentParams);
    return *pCurrentParams;
}

CChainParams& Params(CBaseChainParams::Network network)
{
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

void SelectParams(CBaseChainParams::Network network)
{
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
