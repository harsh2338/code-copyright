import React, { useState, useEffect } from "react";
import PlagiarismContract from "./contracts/PlagiarismContract.json";
import getWeb3 from "./getWeb3";
import ipfs from "./ipfs";
import "./App.css";
import DragDrop from "./components/DragDrop";

function App() {
	const [lang, setLang] = useState(null);
	const [file, setFile] = useState(null);
	const [web3, setWeb3] = useState(null);
	const [contract, setContract] = useState(null);
	const [accounts, setAccounts] = useState(null);
	const [hashSet, setHashSet] = useState(null);
	const [codeFingerprint, setCodeFingerprint] = useState(null);
	const [buffer, setBuffer] = useState(null);
	const [ipfsHash, setIpfsHash] = useState("");
	const [data, setData] = useState("");
	const langIndexes = {
		java: 0,
		python: 1,
		cpp: 2,
		js: 3,
	};

	useEffect(() => {
		getData();
	}, [ipfsHash]);

	useEffect(() => {
		async function fetchData() {
			try {
				// Get network provider and web3 instance.
				const web3 = await getWeb3();

				// Use web3 to get the user's accounts.
				const accounts = await web3.eth.getAccounts();

				// Get the contract instance.
				const networkId = await web3.eth.net.getId();
				const deployedNetwork = PlagiarismContract.networks[networkId];
				const instance = new web3.eth.Contract(
					PlagiarismContract.abi,
					deployedNetwork && deployedNetwork.address
				);

				// Set web3, accounts, and contract to the state
				setWeb3(web3);
				setContract(instance);
				setAccounts(accounts);
			} catch (error) {
				// Catch any errors for any of the above operations.
				alert(
					`Failed to load web3, accounts, or contract. Check console for details.`
				);
				console.error(error);
			}
		}

		if (!codeFingerprint) {
			fetchData();
		} else {
			sendToContract();
		}
	}, [codeFingerprint]);

	const setSelectedFile = (selectedFile) => {
		setFile(selectedFile);
		const reader = new FileReader();
		reader.readAsArrayBuffer(selectedFile);
		reader.onloadend = () => {
			setBuffer(Buffer(reader.result));
			console.log("buffer", reader.result);
		};
	};

	const sendToContract = async () => {
		await contract.methods
			.uploadFile(
				file.size,
				ipfsHash,
				file.name,
				"some desc",
				codeFingerprint,
				hashSet
			)
			.send({ from: accounts[0] });
	};

	var onLangChange = (e) => {
		setLang(e.target.value);
	};

	// var onFileChange = async (e) => {
	// 	setFile(e.target.files[0]);
	// 	const reader = new FileReader();
	// 	reader.readAsArrayBuffer(e.target.files[0]);
	// 	reader.onloadend = () => {
	// 		setBuffer(Buffer(reader.result));
	// 		console.log("buffer", reader.result);
	// 	};
	// };

	var onSubmit = async (e) => {
		e.preventDefault();
		if (!file || !lang || lang === "Select") {
			console.log("Please choose a language and upload the file properly");
			return;
		}
		ipfs.add(buffer).then((res) => {
			setIpfsHash(res["path"]);
			console.log("IPFS Hash", res["path"]);
			const reader = new FileReader();
			reader.onload = async (e) => {
				let text = e.target.result;
				const langIndex = langIndexes[lang];
				fetch("http://localhost:8000", {
					method: "POST",
					headers: {
						"Content-Type": "application/json",
					},
					body: JSON.stringify({
						data: text,
						langIndex: langIndex,
					}),
				})
					.then((res) => res.json())
					.then((data) => {
						setHashSet(data["hashSet"]);
						setCodeFingerprint(data["codeFingerprint"]);
					});
			};
			reader.readAsText(file);
			console.log("SUBMITTED");
		});
	};

	const getData = async () => {
		if (ipfsHash !== "") {
			const stream = ipfs.cat(ipfsHash);
			let data = "";

			for await (const chunk of stream) {
				// chunks of data are returned as a Buffer, convert it back to a string
				for (const x of chunk) data += String.fromCharCode(x);
			}

			setData(data);
		}
	};

	return web3 ? (
		<div className="App">
			<header>Code Copyright Management and Code Plagiarism Detection</header>
			<br />
			<DragDrop setSelectedFile={setSelectedFile} />
			<br />
			<br />
			<label htmlFor="language">Select the language</label>
			<select name="language" id="language" onChange={(e) => onLangChange(e)}>
				<option value="Select">Select</option>
				<option value="js">Javascript</option>
				<option value="cpp">C++</option>
				<option value="java">JAVA</option>
				<option value="python">Python</option>
			</select>
			<br />
			<button type="submit" onClick={onSubmit}>
				Submit
			</button>
			<p>{data}</p>
		</div>
	) : (
		<div>Loading Web3, accounts, and contract...</div>
	);
}

export default App;
