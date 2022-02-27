import Web3 from "web3";
import { RelayProvider } from '@opengsn/provider';

const getWeb3 = () =>
  new Promise((resolve, reject) => {
    // Wait for loading completion to avoid race conditions with web3 injection timing.



    window.addEventListener("load", async () => {
      // Modern dapp browsers...
      if (window.ethereum) {

        				// Get network provider and web3 instance.

    console.log('**************************1*************');
    var web3 = new Web3('http://127.0.0.1:8545');
    web3.eth.transactionPollingTimeout = 5000;
    web3.eth.transactionConfirmationBlocks = 2;
    console.log('**************************2*************');

    const configuration = {
      relayHubAddress: '0x621fCEeC12E239114E0231Fa5f72BeCEC9A464af',
      paymasterAddress: '0xA817E734c8BE50e5D1Df8d51c82798C1BaABa26D',
      forwarderAddress: '0x027bf173A824D1eAa360b01ddd4C45146C01BA53',
      loggerConfiguration: {
        logLevel: 'debug',
      },
      relayRegistrationLookupBlocks: 60000,
      sliceSize: 1,
    };
    console.log('***********************3 WEB ****************');
    const provider = await RelayProvider.newProvider({
      provider: web3.currentProvider,
      config: configuration,
    }).init();
    console.log('***********************4 WEB Provided ****************');
    console.log(provider);
    web3 = new Web3(provider);

        // const provider = await RelayProvider.newProvider({ provider: Web3.currentProvider, config }).init()
        // const web3 = new Web3(provider);



        // const web3 = new Web3(window.ethereum);
        try {
          // Request account access if needed
          await window.ethereum.enable();
          // Accounts now exposed
          resolve(web3);
        } catch (error) {
          reject(error);
        }
      }
      // Legacy dapp browsers...
      else if (window.web3) {

        //have not added GSN here
        // Use Mist/MetaMask's provider.
        const web3 = window.web3;
        console.log("Injected web3 detected.");
        resolve(web3);
      }
      // Fallback to localhost; use dev console port by default...
      else {


            // console.log('**************************1*************');
            // var web3 = new Web3('http://127.0.0.1:8545');
            // web3.eth.transactionPollingTimeout = 5000;
            // web3.eth.transactionConfirmationBlocks = 2;
            // console.log('**************************2*************');

            // const configuration = {
            //   relayHubAddress: '0xe9Bd338c2e01C76cee66161eF706CBb6E0FCa6E5',
            //   paymasterAddress: '0xd8a562D9EaF925138656B0680813B2Fd353cb7Aa',
            //   // their accept-all paymaster
            //   // paymasterAddress: '0xcA94aBEdcC18A10521aB7273B3F3D5ED28Cf7B8A',
            //   forwarderAddress: '0x396292EfC0f4d63d40E36c36ef26c80067485312',
            //   // ourContract: '0xAd7879348C00AD6E5c88E418b7E66A0D386Ee733',
            //   loggerConfiguration: {
            //     logLevel: 'debug',
            //   },
            //   // preferredRelays: ['0x1d89e298a3aB270F4E0644D6dA46C6E001b34e3A'],
            //   relayRegistrationLookupBlocks: 60000,
            //   sliceSize: 1,
            // };
            // console.log('***********************3 WEB ****************');
            // const provider = await RelayProvider.newProvider({
            //   provider: web3.currentProvider,
            //   config: configuration,
            // }).init();
            // console.log('***********************4 WEB Provided ****************');
            // console.log(provider);
            // web3 = new Web3(provider);

        // const provider = await RelayProvider.newProvider({ provider: Web3.currentProvider, config }).init()
        // const web3 = new Web3(provider);

        // const provider = new Web3.providers.HttpProvider(
        //   //"http://172.19.0.1:8545"//
        //   "http://127.0.0.1:8545"
        // );
        // const web3 = new Web3(provider);
        console.log("No web3 instance injected, using Local web3.");
        resolve(web3);
      }
    });
  });

export default getWeb3;
