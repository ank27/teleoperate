import React from 'react';
import MuiThemeProvider from 'material-ui/styles/MuiThemeProvider'

const style = {
	wrap: {
		display: 'flex',
		minHeight: '100vh',
		flexDirection: 'column'
	},
	main: {
		flex: '1'
	}
}

const App = (props) => {
	return (
		<MuiThemeProvider>
			<div style= {style.wrap}>
				<div style={style.main}>
					{props.children}
				</div>
			</div>
		</MuiThemeProvider>
	)
}

export default App
