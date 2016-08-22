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

const dispatchProps = ({
	onKeyPress() {
		console.log('heard this event')
	}
})

export default connect(null,dispatchProps)(Rep)
