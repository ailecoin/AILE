AILE Core integration/staging repository
=====================================

[![AILE COIN](https://github.com/ailecoin/AILE/blob/master/img/ailecoin.png)](http://www.ailecoin.com)


AileCoin is an experimental digital currency that enables anonymous, instant
payments to anyone, anywhere in the world. AileCoin uses peer-to-peer technology
to operate with no central authority: managing transactions and issuing money
are carried out collectively by the network. AileCoin Core is the name of the open
source software which enables the use of this currency.

For more information, the AileCoin Core software,
More information at [www.ailecoin.com](https://www.ailecoin.com)


### Coin Specs

<table>
<tr><td>Abbr</td><td>AILE</td></tr>
<tr><td>P2Pport</td><td>59871</td></tr>
<tr><td>RPCport</td><td>59872</td></tr>
<tr><td>Timestamp</td><td>1562155595</td></tr>
<tr><td>Nodes</td><td>220.123.210.101</td></tr>
<tr><td>Algo</td><td>Quark</td></tr>
<tr><td>Block Time</td><td>60 Seconds</td></tr>
<tr><td>Difficulty Retargeting</td><td>Every Block</td></tr>
<tr><td>Max Coin Supply</td><td>1,000,000,000 AILE</td></tr>
<tr><td>Min Coin for Masternode Staking</td><td>1,000 AILE</td></tr>
<tr><td>Premine</td><td>60,000 AILE*</td></tr>
</table>


### Reward Distribution

<table>
<th colspan=4>Genesis Block</th>
<tr><th>Block Height</th><th>Reward Amount</th><th>Notes</th></tr>
<tr><td>1</td><td>60,000 AILE</td><td>Initial Pre-mine</td></tr>
</table>

### PoW Rewards Breakdown

<table>
<th>Block Height</th><th>Masternodes</th><th>Miner</th><th>Budget</th>
<tr><td>2-43200</td><td>20% (50 AILE)</td><td>80% (200 AILE)</td><td>N/A</td></tr>
<tr><td>43201-151200</td><td>20% (50 AILE)</td><td>70% (200 AILE)</td><td>10% (25 AILE)</td></tr>
<tr><td>151201-259200</td><td>45% (22.5 AILE)</td><td>45% (22.5 AILE)</td><td>10% (5 AILE)</td></tr>
</table>

### PoS Rewards Breakdown

<table>
<th>Phase</th><th>Block Height</th><th>Reward</th><th>Masternodes & Stakers</th><th>Budget</th>
<tr><td>Phase 0</td><td>259201-302399</td><td>50 AILE</td><td>90% (45 AILE)</td><td>10% (5 AILE)</td></tr>
<tr><td>Phase 1</td><td>302400-345599</td><td>45 AILE</td><td>90% (40.5 AILE)</td><td>10% (4.5 AILE)</td></tr>
<tr><td>Phase 2</td><td>345600-388799</td><td>40 AILE</td><td>90% (36 AILE)</td><td>10% (4 AILE)</td></tr>
<tr><td>Phase 3</td><td>388800-431999</td><td>35 AILE</td><td>90% (31.5 AILE)</td><td>10% (3.5 AILE)</td></tr>
<tr><td>Phase 4</td><td>432000-475199</td><td>30 AILE</td><td>90% (27 AILE)</td><td>10% (3 AILE)</td></tr>
<tr><td>Phase 5</td><td>475200-518399</td><td>25 AILE</td><td>90% (22.5 AILE)</td><td>10% (2.5 AILE)</td></tr>
<tr><td>Phase 6</td><td>518400-561599</td><td>20 AILE</td><td>90% (18 AILE)</td><td>10% (2 AILE)</td></tr>
<tr><td>Phase 7</td><td>561600-604799</td><td>15 AILE</td><td>90% (13.5 AILE)</td><td>10% (1.5 AILE)</td></tr>
<tr><td>Phase 8</td><td>604800-647999</td><td>10 AILE</td><td>90% (9 AILE)</td><td>10% (1 AILE)</td></tr>
<tr><td>Phase 9</td><td>648000-1154203</td><td>5 AILE</td><td>90% (4.5 AILE)</td><td>10% (0.5 AILE)</td></tr>
<tr><td>Phase X</td><td>1154203-¡Ä</td><td>6 AILE</td><td>84% (5 AILE/zAILE)</td><td>16% (1 AILE)</td></tr>
</table>




### License

AileCoin Core is released under the terms of the MIT license. See [COPYING](COPYING) for more
information or see https://opensource.org/licenses/MIT.

### Development Process

The `master` branch is meant to be stable. Development is normally done in separate branches.
[Tags](https://github.com/pointofpublic/pointofpublic/tags) are created to indicate new official,
stable release versions of AileCoin Core.

The contribution workflow is described in [CONTRIBUTING.md](CONTRIBUTING.md).
