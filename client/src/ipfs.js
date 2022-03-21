const ipfsClient = require("ipfs-http-client");
const ipfs = ipfsClient.create({
	host: "ipfs.infura.io",
	port: 5001,
	protocol: "https",
});
    // const ipfs = ipfsClient('/ip4/127.0.0.1/tcp/5001')

export default ipfs;
