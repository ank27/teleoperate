const initState = ''

export default (state= initState,action) => {
	switch(action.type) {
		case 'SET_AXIS_AND_DIRECTION':
			return	action.payload
		default:
			return ''
	}
}	
