import React from 'react';
import { connect } from 'react-redux'

import {Grid, Row, Col} from 'react-bootstrap'
import FontAwesome from 'react-fontawesome'

const style = {
	div: {
		borderStyle: 'solid',
		borderColor: 'red',
		lineHeight: 6
	}
}

const Rep = ({
	onKeyPress,
}) => {
		return (
			<Grid>
				<Row>
					<Col sm={12}>
						<p> Keep focus in this container to teleoperate</p>
					</Col>
				</Row>

				<Row>
					<Col sm={12}>
						<div	onKeyDown={onKeyPress} 
							contentEditable={true} 
							style = {style.div} 
							value='foo'
						>
						</div>
					</Col>
				</Row>

				<Row>
					<Col sm={2} smOffset={4} >
						<h1><FontAwesome name='arrow-left'/></h1>
					</Col>
					<Col sm={2}>
						<h1><FontAwesome name='arrow-right' /></h1>
					</Col>
				</Row>
			</Grid>
		)
}

const dispatchProps = (dispatch) => ({
	onKeyPress(e) {
		let move = '';
		switch(e.keyCode) {
			case '38': //UP 
				move = 'z+'
				break
			case '40': //DOWN
				move = 'z-'
				break
			case '37': //LEFT
				move = 'x+'
				break
			case '39': //RIGHT
				move = 'x-'
				break
			default:
				break
		}
		
		if(move=='') 
			return

		dispatch({type: 'SET_AXIS_AND_DIRECTION', payload: move});
	}
})

export default connect(null,dispatchProps)(Rep)
