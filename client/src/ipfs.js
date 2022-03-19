const ipfsClient = require("ipfs-http-client");
const ipfs = ipfsClient.create({
	host: "127.0.0.1",
	port: 5001,
	protocol: "http",
});
    // const ipfs = ipfsClient('/ip4/127.0.0.1/tcp/5001')

export default ipfs;
