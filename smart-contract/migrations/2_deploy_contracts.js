const PlagiarismContract = artifacts.require("PlagiarismContract");
const NaivePaymasterContract = artifacts.require("NaivePaymaster");

module.exports = function (deployer) {
  deployer.deploy(PlagiarismContract);
  deployer.deploy(NaivePaymasterContract);
};
