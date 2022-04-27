const AccessControlContract = artifacts.require("AccessControlContract");
contract("Test AccessControlContract", async (accounts) => {

    it("Checking if adding and removing permissions is possible", async()=>{
        const docCID = "QmbWqxBEKC3P8tqsKc98xmWNzrzDtRLMiMPL8wBuTGsMnR";
        const address = "0x71C7656EC7ab88b098defB751B7401B5f6d8976F";
        const contract = await AccessControlContract.deployed();

        var res =await contract.doesUserHavePermission(docCID,address);
        console.log("Should be false: ");
        console.log(res);

        // await contract.addPermission(docCID,address);
        // res =await contract.doesUserHavePermission(docCID,address);
        // console.log("Should be true: ");
        // console.log(res);
        // await contract.removePermission(docCID,address);
        // res =await contract.doesUserHavePermission(docCID,address);
        // console.log("Should be false: ");
        // console.log(res);       
    })
});