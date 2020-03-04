const fs = require('fs');
const xml2js = require('xml2js');

const resultFn = 'levels.bin';

fs.closeSync(fs.openSync(resultFn, 'w'));
const tmx = fs.readFileSync('levels.tmx', { encoding: 'utf8' });

const parser = new xml2js.Parser({
	charkey: 'text',
	normalize: true,
	mergeAttrs: true,
	explicitArray: false,
	preserveChildrenOrder: true
});

parser.parseString(tmx, (e, result) => {
	if (e) {
		console.error(e);
	}
	else {
		const levels = (result.map && result.map.layer) || [];
		levels.forEach(level => {
			const props = (level.properties && level.properties.property) || [];
			const levelData = new Buffer(96); // (level.width * level.height) + props.length

			const data = level.data;
			if (data && data.encoding === 'csv' && data.text) {
				const values = data.text.replace(/\s+/g, '').split(',');

				let offset = 0;
				for (; offset < values.length; offset++) {
					let value = parseInt(values[offset]) || 0;
					if (value >= 28 && value < 32) {
						value = (value - 16) | 64;
					}
					else if (value === 24) {
						value = 3 | 64;
					}

					levelData.writeUInt8(value, offset);
				}
				for (const prop of props) {
					levelData.writeUInt8(parseInt(prop.value) || 0, offset++);
				}

				fs.appendFileSync(resultFn, levelData);
			}
		});
	}
});
