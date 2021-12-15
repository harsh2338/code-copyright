const PlagiarismContract = artifacts.require("PlagiarismContract");

module.exports = function (deployer) {
  deployer.deploy(PlagiarismContract);
};
